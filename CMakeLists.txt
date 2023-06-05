cmake_minimum_required(VERSION 3.12)
project(sorts)

set(SOURCES
    src/main.cpp
    src/sorts.hpp

    src/bubble_sort.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE -Ofast -march=native -std=c++17)

if(DEFINED BUBBLE)
    target_compile_options(${PROJECT_NAME} PRIVATE -DBUBBLE)
endif()
