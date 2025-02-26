# Define problem test directories
set(TESTS_PROBLEMS_DIR ${CMAKE_SOURCE_DIR}/tests/problems)
set(SOLUTIONS_DIR ${CMAKE_SOURCE_DIR}/solutions)
set(EXCLUSION_FILE ${CMAKE_SOURCE_DIR}/excluded_tests.txt)

# Read excluded tests from file
set(EXCLUDED_TESTS "")
if(EXISTS ${EXCLUSION_FILE})
    file(READ ${EXCLUSION_FILE} EXCLUDED_TESTS)
    string(REPLACE "\n" ";" EXCLUDED_TESTS ${EXCLUDED_TESTS})
endif()

# Build problem-specific tests
file(GLOB PROBLEM_TEST_DIRS "${TESTS_PROBLEMS_DIR}/*")
foreach(TEST_DIR ${PROBLEM_TEST_DIRS})
    get_filename_component(PROBLEM_NAME ${TEST_DIR} NAME)

    # Skip excluded tests
    list(FIND EXCLUDED_TESTS ${PROBLEM_NAME} EXCLUDED)
    if(NOT EXCLUDED EQUAL -1)
        message(WARNING "Skipping test for problem: ${PROBLEM_NAME} (excluded).")
        continue()
    endif()

    # Only include tests if the solution exists
    if(EXISTS "${SOLUTIONS_DIR}/${PROBLEM_NAME}/solution.cpp")
        message(STATUS "Adding problem test: ${PROBLEM_NAME}")
        add_subdirectory(${TEST_DIR})
    else()
        message(WARNING "Skipping problem test: ${PROBLEM_NAME} (solution not found)")
    endif()
endforeach()
