cmake_minimum_required(VERSION 3.21)
project(RedBlackTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(RedBlackTree main.cpp)

include_directories(src)

# use configure_file to transfer cmake-build-debug/database.txt to root directory
configure_file(
    ${CMAKE_CURRENT_BINARY_DIR}/database.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/database.txt
    COPYONLY
)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(RedBlackTree src)

