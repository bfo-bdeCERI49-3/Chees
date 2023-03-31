cmake_minimum_required(VERSION 3.15)
project(Chees)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./src/)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL REQUIRED sdl2)
pkg_check_modules(SDL_IMAGE REQUIRED SDL2_image)

add_executable(Chees
        src/pawns/pawn.cpp
        src/pawns/bishop.cpp
        src/pawns/rook.cpp
        src/pawns/king.cpp
        src/pawns/queen.cpp
        src/pawns/knight.cpp
        src/board/board.cpp
        front.cpp
        src/tests/main.cpp
)
target_link_libraries(Chees PUBLIC ${SDL_IMAGE_LIBRARIES} ${SDL2_LIBRARY})
target_include_directories(Chees PUBLIC ${SDL2_INCLUDE_DIRS})
target_compile_options(Chees PUBLIC ${SDL2_CFLAGS_OTHER})
