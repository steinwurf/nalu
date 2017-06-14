// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include "type.hpp"

#include <cassert>
#include <string>

namespace nalu
{
/// @return Human readable message corresponding to an error code
inline std::string type_to_string(nalu::type type)
{
    switch (type)
    {
#define NALU_TYPE_TAG(value,id,msg,vcl)      \
                case nalu::type::id: return std::string(msg);
#include "type_tags.hpp"
#undef NALU_TYPE_TAG
    default:
        assert(0 && "Invalid NALU type received!");
        return "";
    }
}
}
