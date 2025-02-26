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

# Build test_runner as a library
add_library(test_runner ${SRC_DIR}/test_runner.cpp)
target_include_directories(test_runner PUBLIC ${INCLUDE_DIR})

# Define the main executable for TestBuilder CLI
add_executable(test_builder_main ${SRC_DIR}/test_builder_main.cpp)
target_link_libraries(test_builder_main test_builder)

# Define the main executable for TestRunner CLI
add_executable(test_runner_main ${SRC_DIR}/test_runner_main.cpp)
target_link_libraries(test_runner_main test_runner)

# Include separate test configurations
include(${CMAKE_SOURCE_DIR}/cmake/CoreTests.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/ProblemTests.cmake)

# Custom target to run all tests
add_custom_target(run_tests
    COMMAND ctest --test-dir ${CMAKE_BINARY_DIR} --output-on-failure
)
