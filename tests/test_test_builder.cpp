#include "test_builder.hpp"
#include <iostream>
#include <cassert>

void testBuildAll() {
    TestBuilder builder;
    std::string buildDir = "test_build_dir";
    int numJobs = 4;

    bool result = builder.buildAll(buildDir, numJobs);
    assert(result && "Failed to build all tests");
    std::cout << "testBuildAll passed." << std::endl;
}

void testBuildTest() {
    TestBuilder builder;
    std::string buildDir = "test_build_dir";
    std::string testName = "test_name";
    int numJobs = 4;

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
