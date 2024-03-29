// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <nalu/to_annex_b_nalu.hpp>

#include <gtest/gtest.h>

/// In the following we test whether our parse can correctly identify the
/// different NALUs produced by an Annex B encoder. We check we can find
/// the right address of the NALU plus the size of the start code.
TEST(test_to_annex_b_nalu, single_nalu)
{
    static const uint8_t nalu_data[] = {0x00, 0x00, 0x00, 0x01, 0x12, 0xab};

    auto nalu = nalu::to_annex_b_nalu(nalu_data, sizeof(nalu_data));

    EXPECT_EQ(nalu.m_data, nalu_data);
    EXPECT_EQ(nalu.m_size, 6U);
    EXPECT_EQ(nalu.m_start_code_size, 4U);
    EXPECT_TRUE(bool(nalu));
}

TEST(test_to_annex_b_nalu, no_nalu_data)
{
    static const uint8_t nalu_data[] = {
        0x00, 0x02, 0x01, 0x12, 0xab, 0x00, 0x02, 0x00, 0x01, 0x12,
        0x00, 0x01, 0x01, 0x12, 0xab, 0x00, 0x0f, 0x00, 0x01, 0x12};

    try
    {
        auto nalu = nalu::to_annex_b_nalu(nalu_data, sizeof(nalu_data));
        (void)nalu;
    }
    catch (std::system_error& error)
    {
        EXPECT_EQ(nalu::error_type::no_annex_b_nalu_data_found, error.code());
    }
}

TEST(test_to_annex_b_nalu, garbage_nalu_data)
{
    static const uint8_t nalu_data[] = {0x01, 0x00, 0x00, 0x01, 0x12, 0xab};

    std::error_code error;
    auto nalu = nalu::to_annex_b_nalu(nalu_data, sizeof(nalu_data), error);
    EXPECT_EQ(nalu::error_type::garbage_found_in_nalu_data, error);
    EXPECT_FALSE(nalu.is_valid());
    EXPECT_FALSE(bool(nalu));
}

TEST(test_to_annex_b_nalu, garbage_nalu_data_exception)
{
    static const uint8_t nalu_data[] = {0x01, 0x00, 0x00, 0x01, 0x12, 0xab};

    try
    {
        auto nalu = nalu::to_annex_b_nalu(nalu_data, sizeof(nalu_data));
        (void)nalu;
    }
    catch (std::system_error& error)
    {
        EXPECT_EQ(nalu::error_type::garbage_found_in_nalu_data, error.code());
    }
}
