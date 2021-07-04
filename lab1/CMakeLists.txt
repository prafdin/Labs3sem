cmake_minimum_required(VERSION 2.8)

project(lab1)

add_library(c_straight_lines "c_straight_lines.cpp")
add_library(cpp_straight_lines "cpp_straight_lines.cpp")

add_executable(lab1 "main.cpp")

target_link_libraries(lab1 c_straight_lines cpp_straight_lines)