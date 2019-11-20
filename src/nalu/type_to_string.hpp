// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "type.hpp"

#include <cassert>
#include <string>

namespace nalu
{
/// @return Human readable message corresponding to a nalu type
inline std::string type_to_string(nalu::type type)
{
    switch (type)
    {
#define NALU_TYPE_TAG(value,id,msg,vcl)      \
                case nalu::type::id: return std::string(msg);
#include "type_tags.hpp"
#undef NALU_TYPE_TAG
    }
    assert(0 && "Invalid NALU type received!");
    return "";
}
}
