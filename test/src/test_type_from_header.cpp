// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <nalu/type_from_header.hpp>

#include <gtest/gtest.h>

TEST(test_type_from_header, api)
{
    EXPECT_EQ(nalu::type::unspecified0, nalu::type_from_header(0x00));
    EXPECT_EQ(nalu::type::non_idr_slice, nalu::type_from_header(0x01));
    EXPECT_EQ(nalu::type::a_slice, nalu::type_from_header(0x02));
    EXPECT_EQ(nalu::type::b_slice, nalu::type_from_header(0x03));
    EXPECT_EQ(nalu::type::c_slice, nalu::type_from_header(0x04));
    EXPECT_EQ(nalu::type::idr_slice, nalu::type_from_header(0x05));
    EXPECT_EQ(nalu::type::sei, nalu::type_from_header(0x06));
    EXPECT_EQ(nalu::type::sequence_parameter_set, nalu::type_from_header(0x07));
    EXPECT_EQ(nalu::type::picture_parameter_set, nalu::type_from_header(0x08));
    EXPECT_EQ(nalu::type::access_unit_delimiter, nalu::type_from_header(0x09));
    EXPECT_EQ(nalu::type::end_of_sequence, nalu::type_from_header(0x0A));
    EXPECT_EQ(nalu::type::end_of_stream, nalu::type_from_header(0x0B));
    EXPECT_EQ(nalu::type::filler_data, nalu::type_from_header(0x0C));
    EXPECT_EQ(nalu::type::sps_extension, nalu::type_from_header(0x0D));
    EXPECT_EQ(nalu::type::prefix_nal_unit, nalu::type_from_header(0x0E));
    EXPECT_EQ(nalu::type::subset_sequence_parameter_set,
              nalu::type_from_header(0x0F));
    EXPECT_EQ(nalu::type::depth_parameter_set, nalu::type_from_header(0x10));
    EXPECT_EQ(nalu::type::reserved_17, nalu::type_from_header(0x11));
    EXPECT_EQ(nalu::type::reserved_18, nalu::type_from_header(0x12));
    EXPECT_EQ(nalu::type::auxiliary_slice, nalu::type_from_header(0x13));
    EXPECT_EQ(nalu::type::extension, nalu::type_from_header(0x14));
    EXPECT_EQ(nalu::type::depth_view_slice, nalu::type_from_header(0x15));
    EXPECT_EQ(nalu::type::reserved22, nalu::type_from_header(0x16));
    EXPECT_EQ(nalu::type::reserved23, nalu::type_from_header(0x17));
    EXPECT_EQ(nalu::type::unspecified24, nalu::type_from_header(0x18));
    EXPECT_EQ(nalu::type::unspecified25, nalu::type_from_header(0x19));
    EXPECT_EQ(nalu::type::unspecified26, nalu::type_from_header(0x1A));
    EXPECT_EQ(nalu::type::unspecified27, nalu::type_from_header(0x1B));
    EXPECT_EQ(nalu::type::unspecified28, nalu::type_from_header(0x1C));
    EXPECT_EQ(nalu::type::unspecified29, nalu::type_from_header(0x1D));
    EXPECT_EQ(nalu::type::unspecified30, nalu::type_from_header(0x1E));
    EXPECT_EQ(nalu::type::unspecified31, nalu::type_from_header(0x1F));

    EXPECT_EQ(nalu::type::unspecified0, nalu::type_from_header(0xE0));
    EXPECT_EQ(nalu::type::unspecified31, nalu::type_from_header(0xFF));
}
