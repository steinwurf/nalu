// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

#include "annex_b_nalu.hpp"
#include "annex_b_nalu_parser.hpp"
#include "error.hpp"

namespace nalu
{
/// Finds the NALUs stored in the memory region.
///
/// @param data Buffer contaning one or more Annex B encoded NALUs
/// @param size The size of the buffer in bytes
/// @return A vector containing the found NALUs
inline std::vector<annex_b_nalu>
to_annex_b_nalus(const uint8_t* data, uint32_t size,
                 std::error_code& error)
{
    assert(data != nullptr);
    assert(size > 0);
    assert(!error);

    std::vector<annex_b_nalu> nalus;

    annex_b_nalu_parser parser(data, size);

    if (parser.at_end())
    {
        error = error_type::no_annex_b_nalu_data_found;
        return std::vector<annex_b_nalu>();
    }

    // Get information for the first NALU
    const uint8_t* nalu_start = parser.nalu();

    if (nalu_start != data)
    {
        error = error_type::garbage_found_in_nalu_data;
        return std::vector<annex_b_nalu>();
    }

    while (!parser.at_end())
    {
        // Fetch the start code size before we search for the next NALU
        // in order to find the end.
        uint32_t start_code_size = parser.start_code_size();

        // Find the next NALU such that we know where the current ends
        parser.advance();

        // The logic here basically is that the end of the NALU is the
        // beginning of the next NALU
        const uint8_t* nalu_end = nullptr;

        if (!parser.at_end())
        {
            nalu_end = parser.nalu();
        }
        else
        {
            // No more NALUs so we set the end as the end of the buffer
            nalu_end = data + size;
        }

        auto type = type_from_header(nalu_start[start_code_size]);
        auto size = nalu_end - nalu_start;

        nalus.emplace_back(nalu_start, size, start_code_size, type);

        nalu_start = nalu_end;
    }

    return nalus;
}

/// Calls to_annex_b_nalus(...) with an error_code and throws an
/// exception if an error is set.
inline std::vector<annex_b_nalu>
to_annex_b_nalus(const uint8_t* data, uint32_t size)
{
    assert(data != nullptr);
    assert(size > 0);

    std::error_code error;
    auto nalus = to_annex_b_nalus(data, size, error);
    throw_if_error(error);
    return nalus;
}
}
