cmake_minimum_required(VERSION 3.15)
project(eblang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(eblang STATIC 
    src/vm/vm.cpp
)

target_include_directories(eblang PUBLIC
    include
)

add_subdirectory(tests)