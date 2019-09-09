// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cassert>
#include <system_error>
#include <string>

#include "error_type.hpp"

namespace nalu
{
/// The error category
class error_category : public std::error_category
{
public:

    /// @return The name of the category
    const char* name() const noexcept override
    {
        return "nalu";
    }

    /// @return Human readable message corresponding to an error code
    std::string message(int ev) const override
    {
        switch (static_cast<error_type>(ev))
        {
#define NALU_ERROR_TAG(id,msg)    \
                    case error_type::id: return std::string(msg);
#include "error_tags.hpp"
#undef NALU_ERROR_TAG
        }

        assert(0 && "Invalid error code received!");
        return "";
    }

    /// @return A reference to the error category
    static const std::error_category& instance()
    {
        static error_category instance;
        return instance;
    }
};
}
