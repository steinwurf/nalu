// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

namespace nalu
{
/// Enumeration of different nalu types, we use a bit of macro
/// uglyness to makes this easy. PHK says this is ok so if you have a
/// problem with it - take it up with him :)
///
/// http://phk.freebsd.dk/time/20141116.html
enum class type
{
#define NALU_TYPE_TAG(value, id, msg, vcl) id = value,
#include "type_tags.hpp"
#undef NALU_TYPE_TAG
};
}
