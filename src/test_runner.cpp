#include "test_runner.hpp"
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <vector>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

namespace fs = std::filesystem;

bool TestRunner::testExists(const std::string& testName, const std::string& buildDir) {
    // Check in the main build directory
    fs::path testExecutable1 = fs::path(buildDir) / testName;
    // Check in test_build_dir (where CMake places built tests)
    fs::path testExecutable2 = fs::path(buildDir) / "test_build_dir" / testName;
    // Check inside tests/ (based on directory structure)
    fs::path testExecutable3 = fs::path(buildDir) / "test_build_dir/tests" / testName;

    if ((fs::exists(testExecutable1) && fs::is_regular_file(testExecutable1)) ||
        (fs::exists(testExecutable2) && fs::is_regular_file(testExecutable2)) ||
        (fs::exists(testExecutable3) && fs::is_regular_file(testExecutable3))) {
        return true;  // Test executable exists
    }

    std::cerr << "❌ Test executable not found: " << testExecutable1 
              << ", " << testExecutable2 
              << ", or " << testExecutable3 << std::endl;
    return false;
}

bool TestRunner::runTest(const std::string& testName, const std::string& buildDir) {
    if (!testExists(testName, buildDir)) {
        std::cerr << RED << "❌ Error: Test '" << testName << "' does not exist!" << RESET << std::endl;
        return false;
    }

    std::string command = "ctest --test-dir " + buildDir + " -R ^" + testName + "$ --output-on-failure | tee test_results.log";
    std::cout << "Running test: " << command << std::endl;

    return std::system(command.c_str()) == 0;
}

bool TestRunner::runAllTests(const std::string& buildDir) {
    std::string command = "ctest --test-dir " + buildDir + " --output-on-failure | tee test_results.log";
    std::cout << "Running all tests: " << command << std::endl;

    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << GREEN << "✅ All tests passed!" << RESET << std::endl;
    } else {
        std::cout << RED << "❌ Some tests failed." << RESET << std::endl;
    }

    return result == 0;
}
