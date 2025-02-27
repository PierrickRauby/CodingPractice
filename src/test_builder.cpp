#include "test_builder.hpp"
#include <iostream>
#include <cstdlib>

bool TestBuilder::buildAll(const std::string& buildDir, int numJobs){
  // BUG: issues with manually building when the directory for the tests does not exist or when it has not been built before
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
