cmake_minimum_required (VERSION 3.10)
project(nalu)

file(GLOB nalu_headers ./src/nalu/*.hpp)

add_library(nalu INTERFACE)
add_library(steinwurf::nalu ALIAS nalu)

target_compile_features(nalu INTERFACE cxx_std_11)

target_include_directories(nalu INTERFACE src/)

install(FILES ${nalu_headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/nalu)
