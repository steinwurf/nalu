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

namespace n4lu
{
    /// Creates an Annex B NALU from the memory region.
    ///
    /// @param data Buffer containing an Annex B encoded NALU
    /// @param size The size of the buffer in bytes
    /// @return The Annex B NALU
    inline annex_b_nalu to_annex_b_nalu(const uint8_t* data, uint32_t size,
                                        std::error_code& error)
    {
        assert(data);
        assert(size > 0);

        annex_b_nalu_parser parser(data, size);

        if (parser.at_end())
        {
            error = error_type::no_annex_b_nalu_data_found;
            return annex_b_nalu();
        }

        if (parser.nalu() != data)
        {
            error = error_type::garbage_found_in_nalu_data;
            return annex_b_nalu();
        }

        annex_b_nalu nalu;
        nalu.m_data = data;
        nalu.m_size = size;
        nalu.m_startcode_size = parser.startcode_size();
        nalu.m_type = nalu_type_from_header(
            data[nalu.m_startcode_size]);

        return nalu;
    }

    /// Calls to_annex_b_nalu(...) with an error_code and throws an
    /// exception if an error is set.
    inline annex_b_nalu to_annex_b_nalu(const uint8_t* data, uint32_t size)
    {
        assert(data != nullptr);
        assert(size > 0);

        std::error_code error;
        auto nalu = to_annex_b_nalu(data, size, error);
        throw_if_error(error);
        return nalu;
    }
}
