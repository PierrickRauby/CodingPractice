#include "test_builder.hpp"
#include <iostream>
#include <cstdlib>
#include <filesystem>


void ensureBuildDirectoryValid(const std::string& buildDir) {
  if (!std::filesystem::exists(buildDir) || 
      !std::filesystem::exists(buildDir + "/CMakeCache.txt")) {
      std::cout << "Initializing build directory: " << buildDir << std::endl;
      std::filesystem::create_directories(buildDir);
      std::string cmakeCmd = "cmake -S . -B " + buildDir;
      if (std::system(cmakeCmd.c_str()) != 0) {
          std::cerr << "Error: Failed to initialize CMake build directory.\n";
          exit(1);
      }
  }
}


bool TestBuilder::buildAll(const std::string& buildDir, int numJobs){
  // BUG: issues with manually building when the directory for the tests does not exist or when it has not been built before
  ensureBuildDirectoryValid(buildDir);
  std::string buildCommand= "cmake --build " + buildDir;
  if(numJobs >1){
    buildCommand+= " --parallel "+std::to_string(numJobs);
  }
  std::cout<<"Building all tests with command: "<< buildCommand<<std::endl;
  return std::system(buildCommand.c_str())==0;
}

bool TestBuilder::buildTest(const std::string& testName, const std::string& buildDir, int numJobs){
  ensureBuildDirectoryValid(buildDir);
  std::string buildCommand="cmake --build " + buildDir + " --target "+testName;
  if(numJobs >1){
    buildCommand+= " --parallel "+std::to_string(numJobs);
  }
  std::cout<<"Building test '"<<testName<<"' with command: "<< buildCommand<<std::endl;
  return std::system(buildCommand.c_str())==0;
}
