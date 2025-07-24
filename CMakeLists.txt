cmake_minimum_required(VERSION 3.10)

# CIS 278 Project 1
project(Project VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Gather all source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(Project ${SOURCES})