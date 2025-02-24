cmake_minimum_required(VERSION 3.10)
project(CodingPractice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Define source and include directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TESTS_CORE_DIR ${CMAKE_SOURCE_DIR}/tests/core)
set(TESTS_INTEGRATION_DIR ${CMAKE_SOURCE_DIR}/tests/integration)
set(TESTS_PROBLEMS_DIR ${CMAKE_SOURCE_DIR}/tests/problems)
set(SOLUTIONS_DIR ${CMAKE_SOURCE_DIR}/solutions)
set(EXCLUSION_FILE ${CMAKE_SOURCE_DIR}/excluded_tests.txt)

# Include directories
include_directories(${INCLUDE_DIR})

# Build test_builder as a library
add_library(test_builder ${SRC_DIR}/test_builder.cpp)
target_include_directories(test_builder PUBLIC ${INCLUDE_DIR})

# Define the main executable for TestBuilder CLI
add_executable(test_builder_main ${SRC_DIR}/test_builder_main.cpp)
target_link_libraries(test_builder_main test_builder)

# Conditionally build test_runner if it exists
if(EXISTS "${SRC_DIR}/test_runner.cpp")
    add_library(test_runner ${SRC_DIR}/test_runner.cpp)
    target_include_directories(test_runner PUBLIC ${INCLUDE_DIR})

    add_executable(test_runner_main ${SRC_DIR}/test_runner_main.cpp)
    target_link_libraries(test_runner_main test_runner)
else()
    message(WARNING "test_runner.cpp not found! Skipping test_runner target.")
endif()

# Conditionally build cptest if it exists
if(EXISTS "${SRC_DIR}/cptest.cpp")
    add_executable(cptest ${SRC_DIR}/cptest.cpp)
    target_link_libraries(cptest test_builder)
else()
    message(WARNING "cptest.cpp not found! Skipping cptest target.")
endif()

# Read excluded tests from file
set(EXCLUDED_TESTS "")
if(EXISTS ${EXCLUSION_FILE})
    file(READ ${EXCLUSION_FILE} EXCLUDED_TESTS)
    string(REPLACE "\n" ";" EXCLUDED_TESTS ${EXCLUDED_TESTS})
endif()

### Core Tests (Unit Tests for `test_builder`)
file(GLOB CORE_TESTS "${TESTS_CORE_DIR}/*.cpp")
foreach(TEST_FILE ${CORE_TESTS})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    # Prevent `test_test_builder` from building itself inside test_build_dir
    if(TEST_NAME STREQUAL "test_test_builder")
        message(STATUS "Skipping self-build of test_test_builder.")
        continue()
    endif()

    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} test_builder)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

### Integration Tests
file(GLOB INTEGRATION_TESTS "${TESTS_INTEGRATION_DIR}/*.cpp")
foreach(TEST_FILE ${INTEGRATION_TESTS})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} test_builder)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

### Problem-Specific Tests
file(GLOB PROBLEM_TEST_DIRS "${TESTS_PROBLEMS_DIR}/*")
foreach(TEST_DIR ${PROBLEM_TEST_DIRS})
    get_filename_component(PROBLEM_NAME ${TEST_DIR} NAME)

    list(FIND EXCLUDED_TESTS ${PROBLEM_NAME} EXCLUDED)
    if(NOT EXCLUDED EQUAL -1)
        message(WARNING "Skipping test for problem: ${PROBLEM_NAME} (excluded).")
        continue()
    endif()

    if(EXISTS "${SOLUTIONS_DIR}/${PROBLEM_NAME}/solution.cpp")
        message(STATUS "Adding problem test: ${PROBLEM_NAME}")
        add_subdirectory(${TEST_DIR})
    else()
        message(WARNING "Skipping problem test: ${PROBLEM_NAME} (solution not found)")
    endif()
endforeach()

# Custom target to run all tests
add_custom_target(run_tests
    COMMAND ctest --test-dir ${CMAKE_BINARY_DIR} --output-on-failure
)

# Custom target to build and run all tests
add_custom_target(build_and_run_tests
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CTEST_COMMAND} --test-dir ${CMAKE_BINARY_DIR} --output-on-failure
)
