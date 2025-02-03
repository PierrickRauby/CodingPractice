cmake_minimum_required(VERSION 3.10)
project(CodingPractice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Define directories for solutions and tests
set(SOLUTIONS_DIR ${CMAKE_SOURCE_DIR}/solutions)
set(TESTS_DIR ${CMAKE_SOURCE_DIR}/tests)
set(EXCLUSION_FILE ${CMAKE_SOURCE_DIR}/excluded_tests.txt)

# Read the list of manually excluded tests into a variable
set(EXCLUDED_TESTS "")
if(EXISTS ${EXCLUSION_FILE})
    file(READ ${EXCLUSION_FILE} EXCLUDED_TESTS)
    string(REPLACE "\n" ";" EXCLUDED_TESTS ${EXCLUDED_TESTS}) # Convert newlines to semicolons (list format)
endif()

# Get all test directories
file(GLOB TEST_DIRS "${TESTS_DIR}/*")

foreach(TEST_DIR ${TEST_DIRS})
    # Extract the problem name from the directory path
    get_filename_component(PROBLEM_NAME ${TEST_DIR} NAME)

    # Skip test if listed in excluded_tests.txt
    list(FIND EXCLUDED_TESTS ${PROBLEM_NAME} EXCLUDED)
    if(NOT EXCLUDED EQUAL -1)
        message(WARNING "Skipping test for problem: ${PROBLEM_NAME} (listed in excluded_tests.txt)")
        continue()
    endif()

    # Check if the corresponding solution exists
    if(EXISTS "${SOLUTIONS_DIR}/${PROBLEM_NAME}/solution.cpp")
        message(STATUS "Adding test for problem: ${PROBLEM_NAME}")
        add_subdirectory(${TEST_DIR})
    else()
        message(WARNING "Skipping test for problem: ${PROBLEM_NAME} (solution not found)")
    endif()
endforeach()

# Target to run all tests
add_custom_target(run_tests COMMAND ctest --test-dir ${CMAKE_BINARY_DIR} --output-on-failure)

# Custom target to build and run tests
add_custom_target(build_test
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CTEST_COMMAND} --test-dir ${CMAKE_BINARY_DIR} --output-on-failure
)

# Add Core components as executables
add_executable(test-runner src/test_runner.cpp)
add_executable(test-builder src/test_builder.cpp)
