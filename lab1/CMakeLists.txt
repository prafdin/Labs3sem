cmake_minimum_required(VERSION 3.8)

project (lab1)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)


add_subdirectory (straight_lines)
add_subdirectory (straight_lines_test)

