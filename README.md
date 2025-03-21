# Coding Practice Tester (cptest)

A command-line tool for testing C++ practice implementations for competitive programming and LeetCode-style problems locally.

## Features

- Run your practice implementations against predefined test cases
- Validate output correctness with Google Test
- Automatically create test templates for new problems
- Check for missing solutions or tests

## Installation

### Prerequisites

- CMake (3.10 or higher)
- C++ compiler with C++17 support
- Google Test library

### Manual Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/CodingPractice.git
   cd CodingPractice
   ```

2. Build the project:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

3. Make the script executable:
   ```bash
   chmod +x cptest.sh
   ```

### Homebrew Installation (Coming Soon)

The project will soon be available as a Homebrew package:

```bash
# Not yet available
brew tap yourusername/cptest
brew install cptest
```

## Usage

### Running Tests for a Specific Problem

```bash
./cptest.sh run problem1
```

### Running All Tests

```bash
./cptest.sh run-all
```

### Creating a New Test

```bash
./cptest.sh create problem2
```

### Checking for Missing Solutions or Tests

```bash
./cptest.sh check-missing
```

### Cleaning the Build Directory

```bash
./cptest.sh clean
```

## Project Structure

- `/solutions/` - Contains your problem solutions
- `/tests/problems/` - Contains tests for each problem
- `/templates/` - Templates for new test cases
- `/src/` - Core implementation files

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.

## Version History

- 0.1.0: Initial release
  - Basic testing functionality
  - Support for running individual and all tests
  - Test creation from templates

## CodingPractice Draft

A repository to store coding practice problems, solutions, and examples. It includes implementations in C++ and other relevant tools to improve problem-solving skills and explore algorithms and data structures.

### Features

- Solutions to various coding problems
- Unit tests to validate correctness
- CMake-based build system for easy compilation
- CI/CD integration for automated testing (if applicable)

### Branches descriptions

- main: The stable branch containing the latest validated changes to the test and infrastructure, this branch **does not contain** solutions.
- structureDev: Development branch for modifying and improving the repository's structure, such as organizing files, updating build systems, or refining the CI/CD pipeline.
- solutions: Contains implemented solutions to coding problems. This branch is updated with verified solutions after testing.
- dev: A working branch for testing and developing solutions before they are finalized and merged into the solutions branch. Use this branch when working on a new problem.

### How to Use

#### Clone the Repository

```bash
git clone https://github.com/PierrickRauby/CodingPractice.git
cd CodingPractice
```

#### Build and Test Locally

1. Create a build directory and configure the project:

    ```bash
    mkdir build
    cd build
    cmake ..
    ```

2. Build the project:

    ```bash
    cmake --build .
    ```

3. Run the tests:

    ```bash
    ctest --output-on-failure
    ```

### Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request for bug fixes, improvements, or new problem solutions.

### Problems and Solutions Index

Here is the list of problems with solutions available in the solution branch
- [x] Problem 1: Two Sum (easy)
- [x] Problem 1071: Greatest Common Divisor of Strings (easy)
- [x] Problem 1108: Defanging an IP Address (easy)
- [x] Problem 1189: Maximum Number of Balloon (easy)
- [x] Problem 1207: Unique Number of Occurences (easy)
- [x] Problem 121: Best Time to Buy and Sell (easy)
- [x] Problem 13: 
- [x] Problem 1380: Lucky Number in a Matrix (easy)
- [x] Problem 1431: Kids With the Greatest Number of Candies (easy)
- [x] Problem 151: Reverse Words in a String (medium)
- [x] Problem 1732: Find the Highest Altitude (easy)
- [x] Problem 1768: Merge String Alternatively (easy)
- [ ] Problem 20: Valid Parentheses (easy)
- [x] Problem 21: Merge Two Sorted Strings (easy)
- [ ] Problem 217:
- [x] Problem 2215: Find the Difference of Two Arrays (easy)
- [x] Problem 2239: Find Closest Number to Zero (easy)
- [x] Problem 228: Summary Ranges (easy)
- [x] Problem 238: Product of Array Except Self (medium)
- [ ] Problem 2390: Removing Stars From a String (medium)
- [x] Problem 242: Valid Anagram (easy)
- [x] Problem 283: Move Zeroes (easy)
- [x] Problem 3: Longest Substring Without Repeating Characters (medium)
- [ ] Problem 334: Increase Triplet Subsequence (medium)
- [ ] Problem 338: 
- [x] Problem 344: Reverse String (easy)
- [x] Problem 345: Reverse Vowels of a String (easy)
- [x] Problem 36: Valid Sudoku (medium)
- [x] Problem 392: Is Subsequence (easy)
- [x] Problem 435: Non-overlaping intervals (medium)
- [ ] Problem 46: 
- [x] Problem 56: Merge Intervals (medium)
- [x] Problem 58: Length of Last Word (easy)
- [x] Problem 605: Can Place Flowers (easy)
- [x] Problem 643: Maximum Average Subarray (easy)
- [x] Problem 682: Baseball Game (easy)
- [x] Problem 724: Find Pivot Index (easy)
- [ ] Problem 739: 
- [x] Problem 771: Jewels and Stones (medium)
- [ ] Probleme 83: Remove Duplicates from Sorted List (easy)
- [x] Problem 88: Merge Sorted Array (easy)
- [ ] Problem 933:
- [x] Problem 977: Square of Sorted Array (easy)

<details><summary><h2> License</h2></summary>

This project is licensed under the MIT License. See the `LICENSE` file for more details.
</details>

### 🔥 Next Steps
 
On top of adding solutions and tests to the repo (bold are bigger tasks)

- [x] Change create_problem.sh to be create_tests.sh
- [x] Create single command to build and run the tests
- [x] Create a new branch with solutions to the problems
- [x] Add solutions and dev branches to pipelines
- [x] Add  a script that tell you what problems are still to do
- [x] clarify the use of each branch /dev/solutions/...
- [x] Investigate HomeBrew package usefulness -> yes, will do one!
- [x] Requirement, Fonctionnal Design, Architecture for HB package `cptest`
- [x] Create a mechanism to  exclude tests and solutions from the pipeline
- [ ] Updated Readme.md to reflect which test and problems are completed

- [ ] **Implement core components (`runner.cpp`, `solution_manager.cpp`)**.
- [x] Verify that runner.cpp satisfies the design doc -> yes but needs to be more than a script
- [x] Architecture and Implementation of test_runner.cpp
- [ ] Architecture and Implementation of test_builder.cpp
- [ ] Architecture and Implementation of cptest.cpp i.e. main excutable
- [ ] test_builder unit tests
- [ ] test_runner unit tests
- [ ] cptest unit tests
- [ ] **Finalize CLI commands**.
- [ ] **Ensure easy installation via Homebrew**.
- [ ] **Expand to Python and Rust after the C++ MVP is stable**.
- [ ] **Eventually also in C**
- [ ] **Make it so the user can easily setup github runner for them**

### Clear actionnable next steps

#### Phase 1: Initial Homebrew Package

- [ ] Add version command to bash script
- [ ] Create GitHub release tag (v0.1.0)
- [ ] Create Homebrew formula
- [ ] Set up Homebrew tap repository
- [ ] Test installation locally

#### Phase 2: C++ Transition

- [ ] Create C++ CLI entry point
- [ ] Implement core commands in C++
  - [ ] Help/version commands
  - [ ] Run test command
  - [ ] Run-all command
  - [ ] Create-test command
- [ ] Update Homebrew formula to support dual implementation
- [ ] Create incremental releases (v0.2.0, v0.3.0, etc.)

#### Phase 3: Polish & Optimization

- [ ] Add man pages
- [ ] Add shell completions
- [ ] Complete transition to C++ implementation
- [ ] Consider submission to Homebrew Core (if widely used)
