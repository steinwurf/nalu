// Copyright Steinwurf ApS 2016.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include <cassert>
#include <cstdint>
#include <ostream>

#include "type_from_header.hpp"
#include "type_to_string.hpp"
#include "type.hpp"

namespace nalu
{
/// Small struct representing an Annex B NALU
struct annex_b_nalu
{
    annex_b_nalu(const uint8_t* data, uint32_t size, uint32_t start_code_size,
                 nalu::type type) :
        m_data(data),
        m_size(size),
        m_start_code_size(start_code_size),
        m_type(type)
    {
        assert(m_data != nullptr);
        assert(m_size >= m_start_code_size);
        assert(m_start_code_size == 3U || m_start_code_size == 4U);
    }

    /// Pointer to the NALU data
    const uint8_t* m_data;

    /// Size of NALU in bytes
    const uint32_t m_size;

    /// Size of the Annex B start code
    const uint32_t m_start_code_size = 0;

    /// The type of the NALU
    const nalu::type m_type;
};

/// Output operator for the annex_b_nalu struct
inline std::ostream& operator<<(std::ostream& os, const annex_b_nalu& nalu)
{
    os << "annex_b_nalu:" << std::endl
       << " data = " << (void*) nalu.m_data << std::endl
       << " size = " << nalu.m_size << std::endl
       << " start_code_size = " << nalu.m_start_code_size << std::endl
       << " type = " << type_to_string(nalu.m_type) << std::endl;

    return os;
}
}
