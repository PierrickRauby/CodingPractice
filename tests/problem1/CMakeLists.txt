# tests/problem1/CMakeLists.txt

# Add the test executable
add_executable(test_problem1 test.cpp)

# Include the directory containing solution.hpp
include_directories(${SOLUTIONS_DIR}/problem1)

# Link the solution file
target_sources(test_problem1 PRIVATE ${SOLUTIONS_DIR}/problem1/solution.cpp)

# Link to Google Test or any required libraries
find_package(GTest REQUIRED)
target_link_libraries(test_problem1 PRIVATE GTest::GTest GTest::Main)

# Register the test with CTest
add_test(NAME test_problem1 COMMAND test_problem1)
