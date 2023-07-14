cmake_minimum_required(VERSION 3.16)
project(Yadro)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Yadro
        src/tape_file.cpp
        src/main.cpp
        src/sorter.cpp
        src/config.cpp
        src/tape_fabric.cpp)

add_executable(test
        test/test.cpp
        src/config.cpp
        src/sorter.cpp
        src/tape_fabric.cpp
        src/tape_file.cpp)
