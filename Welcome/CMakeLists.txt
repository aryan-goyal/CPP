cmake_minimum_required(VERSION 3.8)
project(Welcome)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Welcome.cpp)
add_executable(Welcome ${SOURCE_FILES})