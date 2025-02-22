# Automatically detect the problem name from the folder name
get_filename_component(PROBLEM_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Add the test executable
add_executable(test_${PROBLEM_NAME} test.cpp)

# Include the directory containing solution.hpp
include_directories(${SOLUTIONS_DIR}/${PROBLEM_NAME})

# Link the solution file
target_sources(test_${PROBLEM_NAME} PRIVATE ${SOLUTIONS_DIR}/${PROBLEM_NAME}/solution.cpp)

# Link to Google Test or any required libraries
find_package(GTest REQUIRED)
target_link_libraries(test_${PROBLEM_NAME} PRIVATE GTest::GTest GTest::Main)

# Register the test with CTest
add_test(NAME test_${PROBLEM_NAME} COMMAND test_${PROBLEM_NAME})

