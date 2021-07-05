cmake_minimum_required(VERSION 3.0)

project(straight_lines)

add_library(c_straight_lines STATIC "c_straight_lines.cpp" "c_straight_lines.h")
add_library(cpp_straight_lines STATIC "cpp_straight_lines.cpp" "cpp_straight_lines.h")

target_include_directories(c_straight_lines PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(cpp_straight_lines PUBLIC ${CMAKE_CURRENT_LIST_DIR})