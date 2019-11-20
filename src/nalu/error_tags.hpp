// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

NALU_ERROR_TAG(unused,
               "Reserved! Errors should never be zero :)")

NALU_ERROR_TAG(no_annex_b_nalu_data_found,
               "No Annex B NALU data found")

NALU_ERROR_TAG(garbage_found_in_nalu_data,
               "Garbage data was found in the NALU data, the Annex B "
               "NALU must start with a 3 or 4 byte startcode")
