cmake_minimum_required(VERSION 3.21)
project(RedBlackTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(RedBlackTree main.cpp)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(RedBlackTree src)

