cmake_minimum_required(VERSION 3.20)
project(lecture1803)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(complex_number complex_number.cpp)