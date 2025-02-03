#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

namespace fs = std::filesystem;

// Function to check if a test exists by checking for its exact directory name
bool test_exists(const std::string& test_name, const std::string& build_dir) {
    fs::path tests_dir = fs::path(build_dir) / "tests";
    if (!fs::exists(tests_dir) || !fs::is_directory(tests_dir)) {
        return false;
    }
    
    for (const auto& entry : fs::directory_iterator(tests_dir)) {
        if (entry.is_directory() && entry.path().filename() == test_name) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    std::string build_dir = fs::current_path().string();
    std::string command = "ctest --test-dir " + build_dir + " --output-on-failure";
    std::string test_name;
    bool is_test_specified = false;

    // Handle additional command-line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--rerun-failed") {
            command += " --rerun-failed";
        } else if (arg == "-j" && i + 1 < argc) {
            command += " -j" + std::string(argv[i + 1]);
            ++i;
        } else if (arg == "-R" && i + 1 < argc) {
            test_name = argv[i + 1];
            is_test_specified = true;
            ++i;
        }
    }

    // If a specific test was requested, check if it exists
    if (is_test_specified) {
        if (!test_exists(test_name, build_dir)) {
            std::cerr << RED << "❌ Error: Test '" << test_name << "' does not exist!" << RESET << std::endl;
            return 1;
        }
        command += " -R ^" + test_name + "$"; // Ensures exact match
    }

    // Capture output in a log file
    command += " | tee test_results.log";

    std::cout << "Running tests using: " << command << std::endl;
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << GREEN << "✅ All tests passed!" << RESET << std::endl;
    } else {
        std::cout << RED << "❌ Some tests failed." << RESET << std::endl;
    }

    return result;
}

