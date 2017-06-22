// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#include <nalu/annex_b_nalu.hpp>

#include <vector>

#include <gtest/gtest.h>

TEST(test_annex_b_nalu, constructor)
{
    // start code size 3
    {
        std::vector<uint8_t> buffer(10);
        uint32_t start_code_size = 3;
        nalu::type type = nalu::type::idr_slice;

        nalu::annex_b_nalu nalu(
            buffer.data(), buffer.size(), start_code_size, type);

        EXPECT_EQ(buffer.data(), nalu.m_data);
        EXPECT_EQ(buffer.size(), nalu.m_size);
        EXPECT_EQ(start_code_size, nalu.m_start_code_size);
        EXPECT_EQ(type, nalu.m_type);
    }

    // start code size 4
    {
        std::vector<uint8_t> buffer(10);
        uint32_t start_code_size = 4;
        nalu::type type = nalu::type::sequence_parameter_set;

        nalu::annex_b_nalu nalu(
            buffer.data(), buffer.size(), start_code_size, type);

        EXPECT_EQ(buffer.data(), nalu.m_data);
        EXPECT_EQ(buffer.size(), nalu.m_size);
        EXPECT_EQ(start_code_size, nalu.m_start_code_size);
        EXPECT_EQ(type, nalu.m_type);
    }
}

TEST(test_annex_b_nalu, output_operator)
{
    uint8_t* data = (uint8_t*) 0xcaca0caca0;
    uint32_t size = 1337;
    uint32_t start_code_size = 4;
    nalu::type type = nalu::type::picture_parameter_set;

    nalu::annex_b_nalu nalu(data, size, start_code_size, type);

    std::stringstream ss;
    ss << nalu;

    auto expected_string =
        "annex_b_nalu:\n"
        " data = 0xcaca0caca0\n"
        " size = 1337\n"
        " start_code_size = 4\n"
        " type = Picture parameter set\n";

    EXPECT_EQ(expected_string, ss.str());
}