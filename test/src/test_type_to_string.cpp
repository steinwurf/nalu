// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <nalu/type_to_string.hpp>

#include <gtest/gtest.h>

TEST(test_type_to_string, api)
{
#define NALU_TYPE_TAG(value, id, msg, vcl) \
    EXPECT_EQ(msg, nalu::type_to_string(nalu::type::id));
#include <nalu/type_tags.hpp>
#undef NALU_TYPE_TAG
}
