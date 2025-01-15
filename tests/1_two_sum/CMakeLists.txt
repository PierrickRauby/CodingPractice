# tests/1_two_sum/CMakeLists.txt

# Add the test executable
add_executable(test_1_two_sum test.cpp)

# Include the directory containing solution.hpp
include_directories(${SOLUTIONS_DIR}/1_two_sum)

# Link the solution file
target_sources(test_1_two_sum PRIVATE ${SOLUTIONS_DIR}/1_two_sum/solution.cpp)

# Link to Google Test or any required libraries
find_package(GTest REQUIRED)
target_link_libraries(test_1_two_sum PRIVATE GTest::GTest GTest::Main)

# Register the test with CTest
add_test(NAME test_1_two_sum COMMAND test_1_two_sum)
