// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF STEINWURF
// The copyright notice above does not evidence any
// actual or intended publication of such source code.

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
            switch(static_cast<error_type>(ev))
            {
                #define nalu_ERROR_TAG(id,msg)    \
                    case error_type::id: return std::string(msg);
                #include "error_tags.hpp"
                #undef nalu_ERROR_TAG
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
