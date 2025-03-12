class Cptest < Formula
    desc "Command-line tool for testing C++ practice implementations"
    homepage "https://github.com/PierrickRauby/CodingPractice"
    url "https://github.com/PierrickRauby/CodingPractice/archive/refs/tags/v0.1.0.tar.gz"
    sha256 "UPDATE_WITH_ACTUAL_SHA256_AFTER_CREATING_RELEASE"
    license "MIT"
  
    depends_on "cmake" => :build
    depends_on "googletest" => :build
  
    def install
      # Build with cmake
      system "cmake", "-S", ".", "-B", "build", *std_cmake_args
      system "cmake", "--build", "build"
      
      # Install bash script and make it executable
      bin.install "cptest.sh" => "cptest"
      chmod 0755, bin/"cptest"
      
      # Install necessary directories
      prefix.install "templates"
    end
  
    test do
      # Basic test to check if the command runs and version is reported
      assert_match "cptest version 0.1.0", shell_output("#{bin}/cptest version")
    end
  end