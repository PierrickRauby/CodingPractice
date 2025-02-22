#ifndef TEST_BUILDER_HPP
#define TEST_BUILDER_HPP

#include <string>


class TestBuilder{
  public:
    //Build all tests with optional parallelism
    static bool buildAll(const std::string& buildDir, int numJobs=1);
    //Build a single test with optional parallelism
    static bool buildTest(const std::string& testName, const std::string& buildDir, int numJobs=1);
};
#endif
