#include <iostream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string build_dir = fs::current_path().string();
    std::string command = "cmake --build " + build_dir;

    std::cout << "Building tests..." << std::endl;
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "✅ Build successful!" << std::endl;
    } else {
        std::cerr << "❌ Build failed!" << std::endl;
    }

    return result;
}

