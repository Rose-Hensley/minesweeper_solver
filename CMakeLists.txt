cmake_minimum_required(VERSION 3.26)
project(minesweeper)

set(CMAKE_CXX_STANDARD 17)

add_executable(minesweeper
        main.cpp
        lib/include/CTurtle.hpp
        lib/include/CImg.h
        lib/src/Renderer.cpp
        lib/include/Renderer.h
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
