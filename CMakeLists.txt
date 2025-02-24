cmake_minimum_required(VERSION 3.10)
project(CodingPractice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Define source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Include directories
include_directories(${INCLUDE_DIR})

# Build test_builder as a library
add_library(test_builder ${SRC_DIR}/test_builder.cpp)
target_include_directories(test_builder PUBLIC ${INCLUDE_DIR})

# Include separate test configurations
include(${CMAKE_SOURCE_DIR}/cmake/CoreTests.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/ProblemTests.cmake)

# Custom target to run all tests
add_custom_target(run_tests
    COMMAND ctest --test-dir ${CMAKE_BINARY_DIR} --output-on-failure
)
