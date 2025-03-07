#!/bin/bash

# Define colors for output formatting
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
NC='\033[0m' # No Color

# Default directory structure
SOLUTIONS_DIR="solutions"
TESTS_DIR="tests/problems"
EXCLUDE_FILE="excluded_tests.txt"
TEMPLATE_DIR="templates"

# Print usage information
print_usage() {
    echo -e "${BLUE}Usage:${NC}"
    echo -e "  ${GREEN}./cptest.sh${NC} ${YELLOW}<command>${NC} [options]"
    echo
    echo -e "${BLUE}Commands:${NC}"
    echo -e "  ${YELLOW}run <problem_name>${NC}       Run tests for a specific problem"
    echo -e "  ${YELLOW}run-all${NC}                  Run tests for all problems"
    echo -e "  ${YELLOW}create <problem_name>${NC}    Create test files for a problem"
    echo -e "  ${YELLOW}check-missing${NC}            Check for missing solutions or tests"
    echo -e "  ${YELLOW}clean${NC}                    Remove build directory and start fresh"
    echo -e "  ${YELLOW}help${NC}                     Show this help message"
    echo
    echo -e "${BLUE}Examples:${NC}"
    echo -e "  ${GREEN}./cptest.sh${NC} ${YELLOW}run${NC} problem1"
    echo -e "  ${GREEN}./cptest.sh${NC} ${YELLOW}run-all${NC}"
    echo -e "  ${GREEN}./cptest.sh${NC} ${YELLOW}create${NC} problem2"
    echo -e "  ${GREEN}./cptest.sh${NC} ${YELLOW}check-missing${NC}"
    echo -e "  ${GREEN}./cptest.sh${NC} ${YELLOW}clean${NC}"
}

# Check if a test exists for a problem
check_test_exists() {
    local problem_name=$1
    if [ ! -d "$TESTS_DIR/$problem_name" ]; then
        return 1
    fi
    return 0
}

# Check if a solution exists for a problem
check_solution_exists() {
    local problem_name=$1
    if [ ! -d "$SOLUTIONS_DIR/$problem_name" ]; then
        return 1
    fi
    return 0
}

# Create a test for a problem
create_test() {
    local problem_name=$1
    local dest_dir="$TESTS_DIR/$problem_name"

    # Create destination directory
    mkdir -p "$dest_dir"

    # Generate files based on templates if available, otherwise create from scratch
    if [ -d "$TEMPLATE_DIR" ]; then
        # Replace placeholders in template files
        sed "s/Problem X/$problem_name/g" "$TEMPLATE_DIR/README.md" > "$dest_dir/README.md"
        sed "s/ProblemX/$problem_name/g" "$TEMPLATE_DIR/test.cpp" > "$dest_dir/test.cpp"
        cp "$TEMPLATE_DIR/CMakeLists.txt" "$dest_dir/CMakeLists.txt"
        echo -e "${GREEN}Copied and updated template files for $problem_name in $dest_dir${NC}"
    else
        # Generate README.md
        echo "# Test Cases for $problem_name" > "$dest_dir/README.md"
        echo "" >> "$dest_dir/README.md"
        echo "This directory contains test cases for $problem_name." >> "$dest_dir/README.md"
        echo "The test implementation is located in \`test.cpp\`." >> "$dest_dir/README.md"
        
        # Generate test.cpp
        cat <<EOL > "$dest_dir/test.cpp"
#include <gtest/gtest.h>
#include "solution.hpp"

TEST($problem_name, SampleTest) {
    Solution sol;
    // TODO: Add meaningful test cases
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
EOL
        
        # Generate CMakeLists.txt
        cat <<EOL > "$dest_dir/CMakeLists.txt"
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
        echo -e "${GREEN}Created files for $problem_name${NC}"
    fi

    echo -e "${GREEN}✅ Test for $problem_name has been set up!${NC}"
}

# Run tests for a specific problem
run_test() {
    local problem_name=$1
    
    # Check if solution exists
    if ! check_solution_exists "$problem_name"; then
        echo -e "${RED}Error: Solution for '$problem_name' not found in $SOLUTIONS_DIR/${NC}"
        return 1
    fi
    
    # Check if tests exist
    if ! check_test_exists "$problem_name"; then
        echo -e "${YELLOW}Warning: Test for '$problem_name' not found in $TESTS_DIR/${NC}"
        read -p "Do you want to create a test for this problem? (y/n): " CREATE_TEST
        if [[ "$CREATE_TEST" == "y" || "$CREATE_TEST" == "Y" ]]; then
            create_test "$problem_name"
            echo -e "${GREEN}Test created. Building project...${NC}"
        else
            return 1
        fi
    fi
    
    # Check if the problem is in the excluded tests list
    if grep -q "$problem_name" "$EXCLUDE_FILE" 2>/dev/null; then
        echo -e "${YELLOW}Warning: '$problem_name' is listed in $EXCLUDE_FILE${NC}"
        read -p "Do you want to run the test anyway? (y/n): " RUN_ANYWAY
        if [[ "$RUN_ANYWAY" != "y" && "$RUN_ANYWAY" != "Y" ]]; then
            return 0
        fi
        echo -e "${YELLOW}Running excluded test...${NC}"
    fi
    
    # Build the project if not already built
    if [ ! -d "build" ]; then
        echo -e "${YELLOW}Build directory not found. Creating and configuring...${NC}"
        mkdir -p build
        cmake -S . -B build
    fi
    
    # Build the specific test
    echo -e "${BLUE}Building test for $problem_name...${NC}"
    cmake --build build --target "test_$problem_name"
    
    # Run the specific test
    echo -e "${BLUE}Running test for $problem_name...${NC}"
    (cd build && ctest -R "^test_$problem_name$" --output-on-failure)
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✅ Tests for $problem_name passed!${NC}"
        return 0
    else
        echo -e "${RED}❌ Tests for $problem_name failed.${NC}"
        return 1
    fi
}

# Run all tests
run_all_tests() {
    # Check if solutions directory exists
    if [ ! -d "$SOLUTIONS_DIR" ]; then
        echo -e "${RED}Error: Solutions directory '$SOLUTIONS_DIR' not found.${NC}"
        return 1
    fi
    
    # Read excluded tests if the file exists
    EXCLUDED_TESTS=()
    if [ -f "$EXCLUDE_FILE" ]; then
        while IFS= read -r line; do
            if [ ! -z "$line" ]; then
                EXCLUDED_TESTS+=("$line")
            fi
        done < "$EXCLUDE_FILE"
        echo -e "${YELLOW}Found excluded tests file. Will skip: ${EXCLUDED_TESTS[@]}${NC}"
    fi
    
    # Build the project
    echo -e "${BLUE}Configuring and building the project...${NC}"
    if [ ! -d "build" ]; then
        mkdir -p build
        cmake -S . -B build
    else
        # Just update the build
        cmake -S . -B build
    fi
    
    # Build all targets
    echo -e "${BLUE}Building all tests...${NC}"
    cmake --build build
    
    # Find all solutions
    SOLUTIONS=$(ls "$SOLUTIONS_DIR")
    FAILED_TESTS=()
    PASSED_TESTS=()
    SKIPPED_TESTS=()
    
    for PROBLEM in $SOLUTIONS; do
        # Skip if in excluded list
        if [[ " ${EXCLUDED_TESTS[@]} " =~ " ${PROBLEM} " ]]; then
            echo -e "${YELLOW}Skipping excluded test: $PROBLEM${NC}"
            SKIPPED_TESTS+=("$PROBLEM")
            continue
        fi
        
        # Skip if no test exists
        if ! check_test_exists "$PROBLEM"; then
            echo -e "${YELLOW}Warning: No test found for $PROBLEM. Skipping.${NC}"
            SKIPPED_TESTS+=("$PROBLEM")
            continue
        fi
        
        echo -e "${BLUE}Running test for $PROBLEM...${NC}"
        (cd build && ctest -R "test_$PROBLEM" --output-on-failure)
        
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}✅ $PROBLEM: Passed${NC}"
            PASSED_TESTS+=("$PROBLEM")
        else
            echo -e "${RED}❌ $PROBLEM: Failed${NC}"
            FAILED_TESTS+=("$PROBLEM")
        fi
    done
    
    # Print summary
    echo -e "\n${BLUE}========== TEST SUMMARY ==========${NC}"
    echo -e "${GREEN}PASSED: ${#PASSED_TESTS[@]}${NC}"
    echo -e "${RED}FAILED: ${#FAILED_TESTS[@]}${NC}"
    echo -e "${YELLOW}SKIPPED: ${#SKIPPED_TESTS[@]}${NC}"
    
    if [ ${#FAILED_TESTS[@]} -gt 0 ]; then
        echo -e "\n${RED}Failed tests:${NC}"
        for TEST in "${FAILED_TESTS[@]}"; do
            echo -e "${RED}- $TEST${NC}"
        done
        return 1
    else
        echo -e "\n${GREEN}All tests passed successfully!${NC}"
        return 0
    fi
}

# Check for missing solutions or tests
check_missing() {
    # Define directories
    local solutions_dir="$SOLUTIONS_DIR"
    local tests_dir="$TESTS_DIR"
    
    # Initialize arrays for missing tests and missing solutions
    missing_solutions=()
    missing_tests=()
    
    # Get the list of problems in each directory
    solution_problems=($(ls "$solutions_dir" 2>/dev/null))
    test_problems=($(ls "$tests_dir" 2>/dev/null))
    
    # Check for problems that have tests but no solutions
    for problem in "${test_problems[@]}"; do
        if [[ ! -d "$solutions_dir/$problem" ]]; then
            missing_solutions+=("$problem")
        fi
    done
    
    # Check for problems that have solutions but no tests
    for problem in "${solution_problems[@]}"; do
        if [[ ! -d "$tests_dir/$problem" ]]; then
            missing_tests+=("$problem")
        fi
    done
    
    # Output results
    echo -e "${BLUE}🔍 Checking for missing solutions and tests...${NC}"
    echo ""
    
    if [[ ${#missing_solutions[@]} -eq 0 ]]; then
        echo -e "${GREEN}✅ All tests have corresponding solutions!${NC}"
    else
        echo -e "${RED}❌ The following problems have tests but NO solutions:${NC}"
        for problem in "${missing_solutions[@]}"; do
            echo -e "  ${RED}- $problem${NC}"
        done
    fi
    
    echo ""
    
    if [[ ${#missing_tests[@]} -eq 0 ]]; then
        echo -e "${GREEN}✅ All solutions have corresponding tests!${NC}"
    else
        echo -e "${YELLOW}❌ The following problems have solutions but NO tests:${NC}"
        for problem in "${missing_tests[@]}"; do
            echo -e "  ${YELLOW}- $problem${NC}"
            read -p "Do you want to create a test for $problem? (y/n): " CREATE_TEST
            if [[ "$CREATE_TEST" == "y" || "$CREATE_TEST" == "Y" ]]; then
                create_test "$problem"
            fi
        done
    fi
}

# Clean build directory and start fresh
clean_build() {
    if [ -d "build" ]; then
        echo -e "${YELLOW}Removing existing build directory...${NC}"
        rm -rf build
    else
        echo -e "${BLUE}No existing build directory found.${NC}"
    fi
    
    echo -e "${BLUE}Creating fresh build directory...${NC}"
    mkdir -p build
    
    echo -e "${BLUE}Configuring project with CMake...${NC}"
    cmake -S . -B build
    
    echo -e "${BLUE}Building project...${NC}"
    cmake --build build
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✅ Project built successfully!${NC}"
        echo -e "${BLUE}You can now run tests using ${GREEN}./cptest.sh run${NC} or ${GREEN}./cptest.sh run-all${NC}${NC}"
        return 0
    else
        echo -e "${RED}❌ Project build failed.${NC}"
        return 1
    fi
}

# Main execution logic
main() {
    # Check if a command was provided
    if [ $# -lt 1 ]; then
        echo -e "${RED}Error: No command specified${NC}"
        print_usage
        exit 1
    fi
    
    # Process the command
    case "$1" in
        run)
            if [ -z "$2" ]; then
                echo -e "${RED}Error: No problem name specified for 'run' command${NC}"
                echo -e "Usage: ${GREEN}./cptest.sh${NC} ${YELLOW}run${NC} <problem_name>"
                exit 1
            fi
            run_test "$2"
            ;;
        run-all)
            run_all_tests
            ;;
        create)
            if [ -z "$2" ]; then
                echo -e "${RED}Error: No problem name specified for 'create' command${NC}"
                echo -e "Usage: ${GREEN}./cptest.sh${NC} ${YELLOW}create${NC} <problem_name>"
                exit 1
            fi
            create_test "$2"
            ;;
        check-missing)
            check_missing
            ;;
        clean)
            clean_build
            ;;
        help)
            print_usage
            ;;
        *)
            echo -e "${RED}Error: Unknown command '$1'${NC}"
            print_usage
            exit 1
            ;;
    esac
}

# Call the main function with all arguments
main "$@"