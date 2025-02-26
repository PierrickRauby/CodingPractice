#include "test_runner.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <buildDir> [testName]" << std::endl;
        return 1;
    }

    std::string buildDir = argv[1];
    TestRunner runner;

    if (argc == 2) {
        // Run all tests
        if (!runner.runAllTests(buildDir)) {
            std::cerr << "Failed to run all tests." << std::endl;
            return 1;
        }
    } else if (argc == 3) {
        // Run specific test
        std::string testName = argv[2];
        if (!runner.runTest(testName, buildDir)) {
            std::cerr << "Failed to run test: " << testName << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Invalid number of arguments." << std::endl;
        return 1;
    }

    std::cout << "Test execution successful." << std::endl;
    return 0;
}
