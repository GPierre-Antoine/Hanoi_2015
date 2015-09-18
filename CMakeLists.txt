cmake_minimum_required(VERSION 3.3)
project(Hanoi_2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Hanoi_2015 ${SOURCE_FILES})