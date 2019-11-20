cmake_minimum_required (VERSION 3.10)
project(nalu)

add_library(nalu INTERFACE)
add_library(steinwurf::nalu ALIAS nalu)

target_compile_features(mts INTERFACE cxx_std_11)

target_include_directories(nalu INTERFACE src/)
