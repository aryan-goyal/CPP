cmake_minimum_required(VERSION 3.8)
project(Bisection_Root_Finding)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Bisection.cpp)
add_executable(Bisection_Root_Finding ${SOURCE_FILES})