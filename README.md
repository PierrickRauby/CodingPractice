# CodingPractice

A repository to store coding practice problems, solutions, and examples. It includes implementations in C++ and other relevant tools to improve problem-solving skills and explore algorithms and data structures.

## Features

- Solutions to various coding problems
- Unit tests to validate correctness
- CMake-based build system for easy compilation
- CI/CD integration for automated testing (if applicable)

## Branches descriptions

- main: The stable branch containing the latest validated changes to the test and infrastructure, this branch **does not contain** solutions.
- structureDev: Development branch for modifying and improving the repository's structure, such as organizing files, updating build systems, or refining the CI/CD pipeline.
- solutions: Contains implemented solutions to coding problems. This branch is updated with verified solutions after testing.
- dev: A working branch for testing and developing solutions before they are finalized and merged into the solutions branch. Use this branch when working on a new problem.

## How to Use

### Clone the Repository

```bash
git clone https://github.com/PierrickRauby/CodingPractice.git
cd CodingPractice
```

### Build and Test Locally

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

## Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request for bug fixes, improvements, or new problem solutions.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

# Todos:

- [x] Change create_problem.sh to be create_tests.sh
- [x] Create single command to build and run the tests
- [x] Create a new branch with solutions to the problems
- [x] Add solutions and dev branches to pipelines
- [x] Add  a script that tell you what problems are still to do
- [x] clarify the use of each branch /dev/solutions/...
- [ ] Working on adding more problems solutions in the solution branch
- [ ] Investigate HomeBrew package usefulness  (in progress)
