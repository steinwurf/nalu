// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <nalu/annex_b_nalu_parser.hpp>

#include <gtest/gtest.h>
#include <type_traits>

/// Test that we terminate if we find nothing
TEST(test_nalu_annexb_nalu_parser, no_nalus)
{
    static const uint8_t nalu_data[] = {0x00, 0x01, 0x00, 0x01, 0x12, 0xab,
                                        0x05, 0x00, 0x07, 0x01, 0x12, 0xab,
                                        0x00, 0x00, 0x06, 0x01, 0x12, 0xab};

    nalu::annex_b_nalu_parser parser(nalu_data, sizeof(nalu_data));

    // The first NALU at that start of the data
    EXPECT_TRUE(parser.at_end());
}

/// In the following we test whether our parse can correctly identify the
/// different NALUs produced by an Annex B encoder. We check we can find
/// the right address of the NALU plus the size of the start code.
TEST(test_nalu_annexb_nalu_parser, single_nalu)
{
    static const uint8_t nalu_data[] = {0x00, 0x00, 0x00, 0x01, 0x12, 0xab};

    nalu::annex_b_nalu_parser parser(nalu_data, sizeof(nalu_data));

    // The first NALU at that start of the data
    EXPECT_EQ(parser.nalu(), nalu_data);
    EXPECT_EQ(parser.start_code_size(), 4U);

    parser.advance();
    EXPECT_TRUE(parser.at_end());
}

/// Test that we can find multiple NALUs
TEST(test_nalu_annexb_nalu_parser, multiple_nalu)
{
    static const uint8_t nalu_data[] = {
        0x00, 0x00, 0x00, 0x01, 0x12, 0xab, 0x00, 0x00, 0x00,
        0x01, 0x12, 0xab, 0x00, 0x00, 0x01, 0x12, 0xab, // <- 3 byte start code
        0x00, 0x00, 0x00, 0x01, 0x12, 0xab};

    nalu::annex_b_nalu_parser parser(nalu_data, sizeof(nalu_data));

    // The first NALU at that start of the data
    EXPECT_EQ(parser.nalu(), nalu_data);
    EXPECT_EQ(parser.start_code_size(), 4U);

    parser.advance();
    EXPECT_FALSE(parser.at_end());

    EXPECT_EQ(parser.nalu(), nalu_data + 6);
    EXPECT_EQ(parser.start_code_size(), 4U);

    parser.advance();
    EXPECT_FALSE(parser.at_end());

    EXPECT_EQ(parser.nalu(), nalu_data + 12);
    EXPECT_EQ(parser.start_code_size(), 3U);

    parser.advance();
    EXPECT_FALSE(parser.at_end());

    EXPECT_EQ(parser.nalu(), nalu_data + 17);
    EXPECT_EQ(parser.start_code_size(), 4U);

    parser.advance();
    EXPECT_TRUE(parser.at_end());
}

/// Test that we can alternate NALU startcode size
TEST(test_nalu_annexb_nalu_parser, alternate_start_code_size)
{
    static const uint8_t nalu_data[] = {
        0x00, 0x00, 0x01, 0x12, 0xab, 0x00, 0x00, 0x00, 0x01, 0x12, 0xab,
        0x00, 0x00, 0x01, 0x12, 0xab, 0x00, 0x00, 0x00, 0x01, 0x12, 0xab};

    nalu::annex_b_nalu_parser parser(nalu_data, sizeof(nalu_data));

    EXPECT_EQ(parser.start_code_size(), 3U);

    parser.advance();
    EXPECT_FALSE(parser.at_end());

    EXPECT_EQ(parser.start_code_size(), 4U);

    parser.advance();
    EXPECT_FALSE(parser.at_end());

    EXPECT_EQ(parser.start_code_size(), 3U);

    parser.advance();
    EXPECT_FALSE(parser.at_end());

    EXPECT_EQ(parser.start_code_size(), 4U);

    parser.advance();
    EXPECT_TRUE(parser.at_end());
}

/// Test that we can alternate NALU startcode size
TEST(test_nalu_annexb_nalu_parser, four_byte_start_code_for_byte_total)
{
    static const uint8_t nalu_data[] = {0x00, 0x00, 0x00, 0x01};

    nalu::annex_b_nalu_parser parser(nalu_data, sizeof(nalu_data));

    EXPECT_TRUE(parser.at_end());
}
