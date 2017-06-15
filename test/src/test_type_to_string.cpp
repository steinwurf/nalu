// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#include <nalu/type_to_string.hpp>

#include <gtest/gtest.h>

TEST(test_type_to_string, api)
{
#define NALU_TYPE_TAG(value,id,msg,vcl) \
    EXPECT_EQ(msg, nalu::type_to_string(nalu::type::id));
#include <nalu/type_tags.hpp>
#undef NALU_TYPE_TAG
}
