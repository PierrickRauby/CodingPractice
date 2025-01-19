#!/bin/bash

# Define base directories
TEMPLATE_DIR="templates"
TEST_DIR="tests"

# Check if a problem number is provided
if [ -z "$1" ]; then
    echo "Usage: ./create_problem.sh <problem_number>"
    exit 1
fi

# Normalize the problem number
RAW_PROBLEM_NUMBER="$1"
if [[ "$RAW_PROBLEM_NUMBER" == _* ]]; then
    PROBLEM_NUMBER="$RAW_PROBLEM_NUMBER"  # Keep as is if already starts with _
else
    PROBLEM_NUMBER="problem$RAW_PROBLEM_NUMBER"  # Default to problemX format
fi

DEST_DIR="$TEST_DIR/$PROBLEM_NUMBER"

# Ensure the destination directory exists
mkdir -p "$DEST_DIR"

# Copy or create files
if [ -d "$TEMPLATE_DIR" ]; then
    # Replace "Problem X" in README.md and "ProblemX" in test.cpp
    sed "s/Problem X/$PROBLEM_NUMBER/g" "$TEMPLATE_DIR/README.md" > "$DEST_DIR/README.md"
    sed "s/ProblemX/$PROBLEM_NUMBER/g" "$TEMPLATE_DIR/test.cpp" > "$DEST_DIR/test.cpp"
    # Copy the default CMakeLists.txt (no need for replacements)
    cp "$TEMPLATE_DIR/CMakeLists.txt" "$DEST_DIR/CMakeLists.txt"
    echo "Copied and updated template files for $PROBLEM_NUMBER in $DEST_DIR"
else
    # Generate README.md dynamically
    echo "# Test Cases for $PROBLEM_NUMBER" > "$DEST_DIR/README.md"
    echo "" >> "$DEST_DIR/README.md"
    echo "This directory contains test cases for $PROBLEM_NUMBER." >> "$DEST_DIR/README.md"
    echo "The test implementation is located in \`test.cpp\`." >> "$DEST_DIR/README.md"
    echo "Created README.md for $PROBLEM_NUMBER"

    # Generate test.cpp dynamically
    cat <<EOL > "$DEST_DIR/test.cpp"
#include <gtest/gtest.h>
#include "solution.hpp"

TEST($PROBLEM_NUMBER, SampleTest) {
    Solution sol;
    // TODO: Add meaningful test cases
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
EOL
    echo "Created test.cpp for $PROBLEM_NUMBER"

    # Copy the default CMakeLists.txt if templates are not available
    cat <<EOL > "$DEST_DIR/CMakeLists.txt"
# Automatically detect the problem name from the folder name
get_filename_component(PROBLEM_NAME \${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Add the test executable
add_executable(test_\${PROBLEM_NAME} test.cpp)

# Include the directory containing solution.hpp
include_directories(\${SOLUTIONS_DIR}/\${PROBLEM_NAME})

# Link the solution file
target_sources(test_\${PROBLEM_NAME} PRIVATE \${SOLUTIONS_DIR}/\${PROBLEM_NAME}/solution.cpp)

# Link to Google Test or any required libraries
find_package(GTest REQUIRED)
target_link_libraries(test_\${PROBLEM_NAME} PRIVATE GTest::GTest GTest::Main)

# Register the test with CTest
add_test(NAME test_\${PROBLEM_NAME} COMMAND test_\${PROBLEM_NAME})
EOL
    echo "Copied default CMakeLists.txt"
fi

echo "Problem directory $PROBLEM_NUMBER has been set up!"

