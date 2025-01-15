cmake_minimum_required(VERSION 3.10)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

# Define directories for solutions and tests
set(SOLUTIONS_DIR ${CMAKE_SOURCE_DIR}/solutions)
set(TESTS_DIR ${CMAKE_SOURCE_DIR}/tests)

# Get all test directories
file(GLOB TEST_DIRS "${TESTS_DIR}/*")

foreach(TEST_DIR ${TEST_DIRS})
    # Extract the problem name from the directory path
    get_filename_component(PROBLEM_NAME ${TEST_DIR} NAME)
    
    # Check if the corresponding solution exists
    if(EXISTS "${SOLUTIONS_DIR}/${PROBLEM_NAME}/solution.cpp")
        message(STATUS "Adding test for problem: ${PROBLEM_NAME}")
        
        # Add the test directory if the solution exists
        add_subdirectory(${TESTS_DIR}/${PROBLEM_NAME})
    else()
        message(WARNING "Skipping test for problem: ${PROBLEM_NAME} (solution not found)")
    endif()
endforeach()

