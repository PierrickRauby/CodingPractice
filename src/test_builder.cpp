#include "test_builder.hpp"
#include <iostream>
#include <cstdlib>

bool TestBuilder::buildAll(const std::string& buildDir, int numJobs){
  std::string buildCommand= "cmake --build " + buildDir;
  if(numJobs >1){
    buildCommand+= " --parallel "+std::to_string(numJobs);
  }
  std::cout<<"Building all tests with command: "<< buildCommand<<std::endl;
  return std::system(buildCommand.c_str())==0;
}

bool TestBuilder::buildTest(const std::string& testName, const std::string& buildDir, int numJobs){
  std::string buildCommand="cmake --build " + buildDir + " --target "+testName;
  if(numJobs >1){
    buildCommand+= " --parallel "+std::to_string(numJobs);
  }
  std::cout<<"Building test '"<<testName<<"' with command: "<< buildCommand<<std::endl;
  return std::system(buildCommand.c_str())==0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <buildDir> <numJobs> [testName]" << std::endl;
        return 1;
    }

    std::string buildDir = argv[1];
    int numJobs = std::stoi(argv[2]);
    TestBuilder builder;

    if (argc == 3) {
        // Build all tests
        if (!builder.buildAll(buildDir, numJobs)) {
            std::cerr << "Failed to build all tests." << std::endl;
            return 1;
        }
    } else if (argc == 4) {
        // Build specific test
        std::string testName = argv[3];
        if (!builder.buildTest(testName, buildDir, numJobs)) {
            std::cerr << "Failed to build test: " << testName << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Invalid number of arguments." << std::endl;
        return 1;
    }

    std::cout << "Build successful." << std::endl;
    return 0;
}
