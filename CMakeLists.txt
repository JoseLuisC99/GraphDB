cmake_minimum_required(VERSION 3.10)

project(GraphDB VERSION 0.1)
configure_file(ProjectConfig.h.in ProjectConfig.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
    ${PROJECT_NAME}
    
    # Main file
    src/main.cpp
)

target_include_directories(GraphDB PUBLIC "${PROJECT_BINARY_DIR}")