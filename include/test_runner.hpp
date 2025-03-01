#ifndef TEST_RUNNER_HPP
#define TEST_RUNNER_HPP

#include <string>

class TestRunner {
public:
    bool testExists(const std::string& testName, const std::string& buildDir);
    bool runTest(const std::string& testName, const std::string& buildDir);
    bool runAllTests(const std::string& buildDir);
};

#endif // TEST_RUNNER_HPP
