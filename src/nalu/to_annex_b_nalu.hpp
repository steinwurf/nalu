// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <cassert>
#include <cstdint>
#include <vector>
#include <memory>

#include "annex_b_nalu.hpp"
#include "annex_b_nalu_parser.hpp"
#include "error.hpp"

namespace nalu
{
/// Creates an Annex B NALU from the memory region.
///
/// @param data Buffer containing an Annex B encoded NALU
/// @param size The size of the buffer in bytes
/// @return The Annex B NALU
inline std::unique_ptr<annex_b_nalu> to_annex_b_nalu(
    const uint8_t* data, uint32_t size, std::error_code& error)
{
    assert(data != nullptr);
    assert(size > 0);

    annex_b_nalu_parser parser(data, size);

    if (parser.at_end())
    {
        error = error_type::no_annex_b_nalu_data_found;
        return nullptr;
    }

    if (parser.nalu() != data)
    {
        error = error_type::garbage_found_in_nalu_data;
        return nullptr;
    }

    auto start_code_size = parser.start_code_size();
    return std::make_unique<annex_b_nalu>(
        data,
        size,
        start_code_size,
        type_from_header(data[start_code_size]));
}

/// Calls to_annex_b_nalu(...) with an error_code and throws an
/// exception if an error is set.
inline std::unique_ptr<annex_b_nalu> to_annex_b_nalu(
    const uint8_t* data, uint32_t size)
{
    assert(data != nullptr);
    assert(size > 0);

    std::error_code error;
    auto nalu = to_annex_b_nalu(data, size, error);
    throw_if_error(error);
    return nalu;
}
}
