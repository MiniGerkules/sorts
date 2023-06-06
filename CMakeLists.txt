cmake_minimum_required(VERSION 3.12)
project(sorts)

set(SOURCES
    src/main.cpp

    src/sorts/sorts.hpp

    src/sorts/bubble_sort.cpp
    src/sorts/insertion_sort.cpp
    src/sorts/reqursive_quick_sort.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE -Ofast -march=native -std=c++17)

option(BUBBLE OFF)          # Variable to turn on bubble sort
option(INSERTION OFF)       # Variable to turn on insertion sort
option(QUICK OFF)           # Variable to turn on quick sort

if(BUBBLE)
    target_compile_options(${PROJECT_NAME} PRIVATE -DBUBBLE)
elseif(INSERTION)
    target_compile_options(${PROJECT_NAME} PRIVATE -DINSERTION)
elseif(QUICK)
    target_compile_options(${PROJECT_NAME} PRIVATE -DQUICK)
endif()
