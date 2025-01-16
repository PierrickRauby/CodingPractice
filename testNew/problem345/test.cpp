#include <gtest/gtest.h>
#include "../main.h"
#include <string>

TEST(reverseVowels, BasicTest) {
    // Inputs
    std::string str1="hello";
    std::string expectedRes="holle";
    //Sol
    Solution sol;
    std::string res=sol.reverseVowels(str1);
    EXPECT_EQ(res, expectedRes);
}

TEST(reverseVowels, BasicTest1) {
    // Inputs
    std::string str1="LeetCode";
    std::string expectedRes="LeotCede";
    //Sol
    Solution sol;
    std::string res=sol.reverseVowels(str1);
    EXPECT_EQ(res, expectedRes);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
