#!/bin/bash

# Define directories
SOLUTIONS_DIR="solutions"
TESTS_DIR="tests"

# Initialize arrays for missing tests and missing solutions
missing_solutions=()
missing_tests=()

# Get the list of problems in each directory
solution_problems=($(ls "$SOLUTIONS_DIR"))
test_problems=($(ls "$TESTS_DIR"))

# Check for problems that have tests but no solutions
for problem in "${test_problems[@]}"; do
    if [[ ! -d "$SOLUTIONS_DIR/$problem" ]]; then
        missing_solutions+=("$problem")
    fi
done

# Check for problems that have solutions but no tests
for problem in "${solution_problems[@]}"; do
    if [[ ! -d "$TESTS_DIR/$problem" ]]; then
        missing_tests+=("$problem")
    fi
done

# Output results
echo "🔍 Checking for missing solutions and tests..."
echo ""

if [[ ${#missing_solutions[@]} -eq 0 ]]; then
    echo "✅ All tests have corresponding solutions!"
else
    echo "❌ The following problems have tests but NO solutions:"
    for problem in "${missing_solutions[@]}"; do
        echo "  - $problem"
    done
fi

echo ""

if [[ ${#missing_tests[@]} -eq 0 ]]; then
    echo "✅ All solutions have corresponding tests!"
else
    echo "❌ The following problems have solutions but NO tests:"
    for problem in "${missing_tests[@]}"; do
        echo "  - $problem"
    done
fi

