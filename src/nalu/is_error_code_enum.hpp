// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <system_error>

#include "error_type.hpp"
#include "make_error_code.hpp"

namespace std
{
/// Reference: http://bit.ly/1RCq7ts
template <>
struct is_error_code_enum<nalu::error_type> : public true_type
{
};
}
