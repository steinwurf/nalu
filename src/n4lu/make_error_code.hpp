// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

#pragma once

#include "error_type.hpp"
#include "error_category.hpp"

namespace n4lu
{
    /// @return An error_code for n4lu errors
    inline std::error_code make_error_code(error_type e)
    {
        return std::error_code(static_cast<int>(e), error_category::instance());
    }
}
