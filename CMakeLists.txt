cmake_minimum_required(VERSION 3.24)
project(Chees)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chees
        board.cpp
        board.h)
