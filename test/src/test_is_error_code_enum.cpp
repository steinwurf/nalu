// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#include <n4lu/is_error_code_enum.hpp>

#include <gtest/gtest.h>

/// Test that our enums convert to error code
TEST(test_is_error_code_enum, convert)
{
    std::error_code error = n4lu::error_type::unused;

    EXPECT_TRUE(error.category() == n4lu::error_category::instance());
    EXPECT_EQ(error.message(), "Reserved! Errors should never be zero :)");
}
