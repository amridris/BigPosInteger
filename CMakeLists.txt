cmake_minimum_required(VERSION 3.8)
project(BigPosInteger)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp bigPosInteger.cpp bigPosInteger.h)
add_executable(BigPosInteger ${SOURCE_FILES})