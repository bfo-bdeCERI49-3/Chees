cmake_minimum_required(VERSION 3.15)
project(Chees)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

include_directories(./src/)

add_executable(Chees
        src/pawns/IPiece.cpp
        src/pawns/pawn.cpp
        src/pawns/fool.cpp
        src/board/board.cpp
        src/board/board.h
        src/pawns/king.hpp src/pawns/knight.hpp src/pawns/queen.hpp src/pawns/rook.hpp src/pawns/knight.cpp)