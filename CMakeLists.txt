cmake_minimum_required(VERSION 3.15)
project(Chees)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

include_directories(./src/)

add_executable(Chees
        src/pawns/pawn.cpp
        src/pawns/fool.cpp
        src/pawns/rook.cpp
        src/pawns/king.cpp
        src/pawns/queen.cpp
        src/pawns/knight.cpp
        src/board/board.cpp
        src/tests/main.cpp
)