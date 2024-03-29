// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

namespace nalu
{
/// Enumeration of different error codes, we use a bit of macro
/// uglyness to makes this easy. PHK says this is ok so if you have a
/// problem with it - take it up with him :)
///
/// http://phk.freebsd.dk/time/20141116.html
///
enum class error_type
{
#define NALU_ERROR_TAG(id, msg) id,
#include "error_tags.hpp"
#undef NALU_ERROR_TAG
};
}
