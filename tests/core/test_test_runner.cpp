#include "test_runner.hpp"
#include <iostream>
#include <cassert>
#include <filesystem>

void testTestExists() {
    TestRunner runner;
    std::string buildDir = "test_build_dir";

    bool result = runner.testExists("test_problem1", buildDir);
    assert(result && "Failed to detect existing test");
    std::cout << "testTestExists passed." << std::endl;
}

void testRunTest() {
    TestRunner runner;
    std::string buildDir = "test_build_dir";
    std::string testName = "test_problem1"; // Replace with an actual test

    bool result = runner.runTest(testName, buildDir);
    assert(result && "Failed to run specific test");
    std::cout << "testRunTest passed." << std::endl;
}

void testRunAllTests() {
    TestRunner runner;
    std::string buildDir = "test_build_dir";

    bool result = runner.runAllTests(buildDir);
    assert(result && "Failed to run all tests");
    std::cout << "testRunAllTests passed." << std::endl;
}

int main() {
    testTestExists();
    testRunTest();
    testRunAllTests();
    std::cout << "All test_runner tests passed." << std::endl;
    return 0;
}
