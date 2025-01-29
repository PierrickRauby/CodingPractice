#include <gtest/gtest.h>
#include "solution.hpp"
#include <string>

TEST(isValid, BasicTest) {
    // Inputs
    std::string str1="()";
    bool expectedRes=true;
    //Sol
    Solution sol;
    bool res=sol.isValid(str1);
    EXPECT_EQ(res, expectedRes);
}

TEST(isValid, BasicTest1) {
    // Inputs
    std::string str1="()[]{}";
    bool expectedRes=true;
    //Sol
    Solution sol;
    bool res=sol.isValid(str1);
    EXPECT_EQ(res, expectedRes);
}

TEST(isValid, BasicTest2) {
    // Inputs
    std::string str1="(]}";
    bool expectedRes=false;
    //Sol
    Solution sol;
    bool res=sol.isValid(str1);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
