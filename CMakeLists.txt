cmake_minimum_required(VERSION 3.27)
project(pudeleczko)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pudeleczko
        main.cpp
        pudelko.h)
