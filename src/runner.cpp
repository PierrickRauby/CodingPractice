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

// Function to check if a test exists by checking for its directory
bool test_exists(const std::string& test_name, const std::string& build_dir) {
    fs::path test_path = fs::path(build_dir) / "tests" / test_name;
    return fs::exists(test_path) && fs::is_directory(test_path);
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
        command += " -R " + test_name;
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
