// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <fstream>
#include <iostream>

#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/crc.hpp>

#include <nalu/to_annex_b_nalus.hpp>

int main(int argc, char* argv[])
{
    if (argc != 2 || std::string(argv[1]) == "--help")
    {
        auto usage = "./nalu_inspect H264_FILE";
        std::cout << usage << std::endl;
        return 0;
    }

    auto file_path = std::string(argv[1]);

    boost::iostreams::mapped_file_source file;
    file.open(file_path);

    std::error_code error;
    auto nalus = nalu::to_annex_b_nalus((uint8_t*)file.data(), file.size(), error);

    if (error)
    {
        std::cout << "Error reading file " << file_path << ": " << error.message()
                  << std::endl;
        file.close();
        return 1;
    }

    for (const auto& nalu : nalus)
    {
        // Calculate checksum without start code
        boost::crc_32_type result;
        result.process_bytes(
            nalu.m_data + nalu.m_start_code_size,
            nalu.m_size - nalu.m_start_code_size);

        std::cout << nalu::type_to_string(nalu.m_type) << " ("
                  << nalu.m_start_code_size << " + "
                  << nalu.m_size - nalu.m_start_code_size
                  << "): "
                  << result.checksum() << std::endl;
    }
    std::cout << "Found " << nalus.size() << " NALUs"
              << " in a file of " << file.size() / 1000 << " kb." << std::endl;

    file.close();
    return 0;
}
