// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include "error_category.hpp"
#include "error_type.hpp"

namespace nalu
{
/// @return An error_code for nalu errors
inline std::error_code make_error_code(error_type e)
{
    return std::error_code(static_cast<int>(e), error_category::instance());
}
}
