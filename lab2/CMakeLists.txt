cmake_minimum_required(VERSION 2.8)

project(lab2)

add_library(set_unical_integer set_unical_integer.cpp)
add_executable(lab2 main.cpp)

target_link_libraries(lab2 set_unical_integer)