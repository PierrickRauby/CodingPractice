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

- Allow users to request **reference implementations** (if available for that problem).
- Allow users to request the addition of a missing reference implementation.
- Add support for **Python** and **Rust**.

#### **Nice-to-Have (Future Improvements)**

- Automated **benchmarking** (runtime/memory profiling).
- Integration with **online problem repositories** (e.g., LeetCode API).
- Support for **custom user-defined test cases**.

---

## 2. Functional Design

### 2.1 CLI Usage

#### ✅ **Running a Test**

```sh
cptest run problem1/my_implementation.cpp
```

- Compiles the practice implementation.
- Runs it against predefined test cases for problem1.
- Compares outputs.

#### ✅ **Checking All Tests**

```sh
cptest run-all rootFolder
```

- Runs all available test cases for all problems located in `rootFolder`.
- The folder must follow the structure:
  ```
  rootFolder/
  ├── problemX/
  │   ├── implementation.cpp
  ├── problemY/
  │   ├── implementation.cpp
  ```

#### ✅ **View a Reference Implementation**

```sh
cptest get-solution problem1
```

- Fetches the reference implementation (if available) from the repository.

#### ✅ **Generating a New Test Case**

```sh
cptest create-test problem1
```

- Generates a new test case using a predefined template.

#### ✅ **Checking for Missing Reference Implementations**

```sh
cptest check-missing
```

- Scans the `tests/` directory to find all available test cases.
- Checks the `solutions/` directory to see if a corresponding reference implementation exists.
- Lists all problems that have test cases but are missing a reference implementation.
- Example output:
  ```
  ⚠️ Missing reference implementations for the following problems:
  - problem2
  - problem4
  ```

### 2.2 Expected Input/Output

**Input:**

- C++ implementation file (`.cpp`)
- Predefined test cases (stored in the `tests/` directory)

**Output:**

- `✅ PASSED`: if the output matches expected results.
- `❌ FAILED`: if the output does not match.
- `⚠️ MISSING`: if no reference implementation exists for a given problem.

### 2.3 Error Handling

- **Compilation Errors** → Display error messages and suggest fixes.
- **Runtime Errors** → Capture segmentation faults, timeouts, etc.
- **Missing Tests** → Provide a warning and suggest generating test cases.

---

## 3. Architecture

### 3.1 High-Level Components

1. **CLI Interface (`cptest`)**
   - Parses commands and arguments.
   - Dispatches tasks based on user input.
2. **Test Runner (`runner.cpp`)**
   - Compiles user code.
   - Executes against test cases.
   - Compares results.
3. **Reference Implementation Provider (`solution_manager.cpp`)**
   - Retrieves reference implementations.
   - Lists available problems and missing reference implementations.
4. **Test Case Generator (`test_generator.cpp`)**
   - Creates new test cases when needed.

### 3.2 Repository Structure

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

### 3.3 Build & Installation

- Uses **CMake** for compilation.
- Installs as a Homebrew package (`brew install cptest`).
- Dependencies are managed via `CMakeLists.txt`.

---

## 🔥 Next Steps

- **Finalize CLI commands**.
- **Implement core components (`runner.cpp`, `solution_manager.cpp`)**.
- **Ensure easy installation via Homebrew**.
- **Expand to Python and Rust after the C++ MVP is stable**.

Let me know if you want refinements or additions! 🚀
