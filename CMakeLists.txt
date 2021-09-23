cmake_minimum_required(VERSION 3.10)

project(GraphDB VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB source_files CONFIGURE_DEPENDS
    "src/*/*.cpp"
    "src/*/*.hpp"
)
file(GLOB test_files CONFIGURE_DEPENDS
    "test/*.cpp"
    "test/*.hpp"
)

add_executable(${PROJECT_NAME} src/main.cpp ${source_files})
add_executable(tests ${test_files} ${source_files})

target_include_directories(GraphDB PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)