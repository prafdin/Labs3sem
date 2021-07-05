cmake_minimum_required(VERSION 3.0)

project(straight_lines_test)

set ( Sources
    straight_lines_test.cpp
)

add_executable(${PROJECT_NAME} ${Sources})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    "c_straight_lines"
    "cpp_straight_lines"
    "gmock_main"
 )


add_test(
    NAME ${PROJECT_NAME} 
    COMMAND ${PROJECT_NAME}
 )

