// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <nalu/is_error_code_enum.hpp>

#include <gtest/gtest.h>

/// Test that our enums convert to error code
TEST(test_is_error_code_enum, convert)
{
    std::error_code error = nalu::error_type::unused;

    EXPECT_TRUE(error.category() == nalu::error_category::instance());
    EXPECT_EQ(error.message(), "Reserved! Errors should never be zero :)");
}
