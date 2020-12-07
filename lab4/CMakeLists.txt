cmake_minimum_required(VERSION 3.8)

project(lab4)

add_library(functions functions.cpp)
add_executable(lab4 "main.cpp")

target_link_libraries(lab4 functions)



