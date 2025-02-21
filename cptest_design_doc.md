# cptest: Design Document

## 1. Requirements

### 1.1 Problem Statement

`cptest` is a command-line tool designed to help users test their **C++ practice implementations** for competitive programming and LeetCode-style problems locally. The tool allows users to:

- Run their practice implementations against predefined test cases.
- Validate output correctness.
- Request a reference implementation for supported problems.

Future extensions will include support for **Python** and **Rust** implementations.

### 1.2 Key Features

#### **Must-Have (MVP)**

- Support **C++** practice implementations.
- Provide predefined test cases.
- Run user practice implementations and compare outputs.
- Display clear **pass/fail** results.

#### **Should-Have (Planned for Expansion)**

- Allow users to request **reference implementations** (if available for that problem) -> maybe by creating issue in the repo?
- Allow users to request the addition of a missing reference implementation -> (same as above)
- Add support for **Python** and **Rust**.

#### **Nice-to-Have (Future Improvements)**

- Automated **benchmarking** (runtime/memory profiling).
- Integration with **online problem repositories** (e.g., LeetCode API).
- Support for **custom user-defined test cases**.

---

## 2. Functional Design

### 2.1 CLI Usage

The `cptest` tool provides command-line functionality to test C++ implementations against predefined test cases, retrieve reference solutions, and manage test cases. Below are the available commands:

#### **2.1.1 cptest run `<file.cpp>`**

**Purpose:** Runs a single C++ implementation against predefined test cases.  

##### **Input:**

- A C++ source file (`.cpp`) containing a solution to a problem.

##### **Expected Output:**

- ✅ **PASSED**: The output matches expected results.
- ❌ **FAILED**: The output does not match.
- ⚠️ **COMPILATION ERROR**: Compilation failed; error messages are shown.
- ⚠️ **MISSING TEST CASES**: No test cases exist for the given problem.

##### **Error Handling:**

- **File not found** → `"Error: File '<file.cpp>' does not exist."`
- **Compilation error** → `"Error: Compilation failed. See output for details."`
- **No matching test cases** → `"Warning: No test cases found for '<file.cpp>'."`

##### **Example Usage:**

```sh
cptest run problems/problem1/my_implementation.cpp
```

---

#### **2.1.2 cptest run-all `<rootFolder>`**

**Purpose:** Runs all available test cases for all problems within a directory.

##### **Input:**

- A directory containing multiple C++ problem implementations.

##### **Expected Output:**

- A summary of results for all implementations in the directory.
- Compilation/runtime failures are displayed.

##### **Error Handling:**

- **Directory not found** → `"Error: Directory '<rootFolder>' does not exist."`
- **No C++ files found** → `"Error: No implementations found in '<rootFolder>'."`
- **Test case directory missing** → `"Warning: Some problems are missing test cases."`

##### **Example Usage:**

```sh
cptest run-all problems/
```

##### **Example Output:**

```
[problem1/my_implementation.cpp] ✅ PASSED
[problem2/my_implementation.cpp] ❌ FAILED (Output mismatch)
[problem3/my_implementation.cpp] ⚠️ COMPILATION ERROR
```

---

#### **2.1.3 cptest get-solution `<problem>`**

**Purpose:** Retrieves a reference implementation for the given problem.

##### **Input:**

- The problem identifier (e.g., `problem1`).

##### **Expected Output:**

- The reference solution, if available.
- ⚠️ **MISSING**: If no reference implementation exists.

##### **Error Handling:**

- **Reference implementation not found** → `"Warning: No reference implementation available for '<problem>'."`
- **Invalid problem name** → `"Error: Problem '<problem>' does not exist."`

##### **Example Usage:**

```sh
cptest get-solution problem1
```

##### **Example Output:**

```cpp
// Reference Implementation for problem1
#include <iostream>
int main() {
    std::cout << "Hello, World!" << std::endl;
}
```

---

#### **2.1.4 cptest create-test `<problem>`**

**Purpose:** Generates a new test case for the specified problem.

##### **Input:**

- The problem identifier.

##### **Expected Output:**

- A new test file is created inside the `tests/` directory.
- A warning is displayed if the test already exists.

##### **Error Handling:**

- **Problem not found** → `"Error: Problem '<problem>' does not exist in the repository."`
- **Test file already exists** → `"Warning: Test file for '<problem>' already exists. Skipping creation."`

##### **Example Usage:**

```sh
cptest create-test problem1
```

##### **Example Output:**

```
✅ Test template created at tests/problem1/test1.txt
```

---

#### **2.1.5 cptest check-missing**

**Purpose:** Checks for missing reference implementations in the repository.

##### **Input:**

- No input required.

##### **Expected Output:**

- A list of problems that have test cases but lack a reference implementation.
- `"All problems have reference implementations."` if nothing is missing.

##### **Error Handling:**

- **No missing solutions** → `"All problems have reference implementations."`
- **Repository structure issue** → `"Error: Unable to check missing implementations. Ensure 'tests/' and 'solutions/' directories exist."`

##### **Example Usage:**

```sh
cptest check-missing
```

##### **Example Output:**

```
⚠️ Missing reference implementations for the following problems:
- problem2
- problem4
```

---

### **2.2 Future CLI Enhancements: Optional Flags & Parameters**

To extend `cptest` functionality in the future, the following optional flags and parameters are proposed:

#### **2.2.1 Global Flags (Applicable to Multiple Commands)**

| Flag | Description | Applicable Commands |
|------|------------|---------------------|
| `--verbose` | Displays detailed logs (compilation steps, test execution details, etc.) | `run`, `run-all`, `create-test` |
| `--quiet` | Suppresses non-error messages for cleaner output | `run`, `run-all`, `check-missing` |
| `--json` | Outputs results in JSON format (useful for CI/CD integration) | `run`, `run-all` |

#### **2.2.2 Command-Specific Flags**

| Command | Flag | Description |
|---------|------|-------------|
| `cptest run` | `--timeout=<seconds>` | Specifies a maximum execution time per test case (default: no limit) |
| `cptest run` | `--ignore-failures` | Continues running tests even if some fail |
| `cptest run-all` | `--parallel=<N>` | Runs tests in parallel using N threads (default: 1) |
| `cptest create-test` | `--overwrite` | Overwrites an existing test case instead of skipping |
| `cptest check-missing` | `--detailed` | Shows additional metadata about missing implementations |

#### **2.2.3 Possible Future Additions**

- `--diff` (for `run`): Displays a side-by-side diff when a test fails.
- `--update-tests` (for `run-all`): Automatically updates test outputs if they mismatch.
- `--list` (for `get-solution`): Lists all available solutions instead of fetching just one.

These flags ensure `cptest` remains extensible for future improvements.

---


## 3. Architecture

### 3.1 Separation of Test Building and Running

To maintain modularity and flexibility, `cptest` will use two separate components:

#### **3.1.1 Test Builder (`test_builder`)**
- Responsible for **compiling** tests before execution.
- Uses `CMake` to ensure tests are built before running.
- Ensures tests are up to date before execution.

#### **3.1.2 Test Runner (`test_runner`)**
- Ensures tests exist.
- Calls `test_builder` before running the tests.
- Executes `ctest` with appropriate filtering options.

`cptest` will wrap both `test_runner` and `test_builder`, using them as APIs.

### 3.2 High-Level Components

1. **CLI Interface (`cptest`)**
   - Parses commands and arguments.
   - Dispatches tasks based on user input.
2. **Test Builder (`test_builder`)**
   - Compiles test binaries.
   - Ensures dependencies are correctly built.
3. **Test Runner (`test_runner`)**
   - Runs tests using `ctest`.
   - Filters tests using `-R` for targeted execution.
4. **Reference Implementation Provider (`solution_manager.cpp`)**
   - Retrieves reference implementations.
   - Lists available problems and missing reference implementations.
5. **Test Case Generator (`test_generator.cpp`)**
   - Creates new test cases when needed.

### 3.3 Repository Structure

```
.
├── CMakeLists.txt    # Build system config
├── README.md         # Documentation
├── solutions/        # Reference implementations
│   ├── problem1/
├── tests/            # Predefined test cases
│   ├── problem1/
├── templates/        # Test case templates
│   ├── test.cpp
├── scripts/          # Helper scripts
│   ├── check_missing_solution.sh
│   ├── create_test.sh
└── src/              # Core logic
    ├── cptest.cpp
    ├── runner.cpp
    ├── solution_manager.cpp
    ├── test_generator.cpp
```

### 3.4 Build & Installation

- Uses **CMake** for compilation.
- Installs as a Homebrew package (`brew install cptest`).
- Dependencies are managed via `CMakeLists.txt`.
