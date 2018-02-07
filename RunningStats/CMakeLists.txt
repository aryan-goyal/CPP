cmake_minimum_required(VERSION 3.8)
project(RunningStats)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES RunningStats.cpp)
add_executable(RunningStats ${SOURCE_FILES})