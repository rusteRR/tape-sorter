cmake_minimum_required(VERSION 3.16)
project(Yadro)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Yadro
        tape.cpp
        main.cpp
        sorter.cpp
        config.cpp)

add_executable(test
        test/test.cpp
        config.cpp
        sorter.cpp
        tape.cpp)
