#include "test_builder.hpp"
#include <iostream>
#include <cassert>
#include <filesystem>
#include <cstdlib>

void testBuildAll() {
    TestBuilder builder;
    std::string buildDir = "test_build_dir";
    int numJobs = 4;

    // Get the absolute path of the project root (where CMakeLists.txt is located)
    std::string sourceDir = std::filesystem::canonical(std::filesystem::path("..")).string();

    // Ensure the build directory exists
    if (!std::filesystem::exists(buildDir)) {
        std::filesystem::create_directory(buildDir);
    }

    // Run cmake configuration inside test_build_dir
    std::string cmakeCommand = "cmake -S " + sourceDir + " -B " + buildDir;
    std::cout << "Running CMake command: " << cmakeCommand << std::endl;
    if (std::system(cmakeCommand.c_str()) != 0) {
        std::cerr << "CMake configuration failed in " << buildDir << std::endl;
        assert(false && "Failed to configure CMake for test_build_dir");
    }

    // Ensure we don't build `test_test_builder` inside test_build_dir
    std::cout << "Skipping self-build of test_test_builder" << std::endl;

    bool result = builder.buildAll(buildDir, numJobs);
    assert(result && "Failed to build all tests");
    std::cout << "testBuildAll passed." << std::endl;
}

void testBuildTest() {
    TestBuilder builder;
    std::string buildDir = "test_build_dir";
    std::string testName = "test_problem1";  // Avoid test_test_builder
    int numJobs = 4;

    // Get the absolute path of the project root
    std::string sourceDir = std::filesystem::canonical(std::filesystem::path("..")).string();

    // Ensure the build directory exists
    if (!std::filesystem::exists(buildDir)) {
        std::filesystem::create_directory(buildDir);
    }

    // Run cmake configuration inside test_build_dir
    std::string cmakeCommand = "cmake -S " + sourceDir + " -B " + buildDir;
    std::cout << "Running CMake command: " << cmakeCommand << std::endl;
    if (std::system(cmakeCommand.c_str()) != 0) {
        std::cerr << "CMake configuration failed in " << buildDir << std::endl;
        assert(false && "Failed to configure CMake for test_build_dir");
    }

    // Now build the test
    bool result = builder.buildTest(testName, buildDir, numJobs);
    assert(result && "Failed to build specific test");
    std::cout << "testBuildTest passed." << std::endl;
}

int main() {
    testBuildAll();
    testBuildTest();
    std::cout << "All tests passed." << std::endl;
    return 0;
}
