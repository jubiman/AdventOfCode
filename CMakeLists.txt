cmake_minimum_required(VERSION 3.23)
project(aoc)

set(CMAKE_CXX_STANDARD 14)

add_executable(aoc main.cpp 2021/one.cpp 2021/one.h filesystem.cpp filesystem.h 2021/two.cpp 2021/two.h 2021/three.cpp 2021/three.h 2021/four.cpp 2021/four.h)
