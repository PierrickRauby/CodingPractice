#include <gtest/gtest.h>
#include "solution.hpp"
#include <string>

TEST(lengthOfLongestSubstring, BasicTest0) {
    // Inputs
    std::string input="abcabcbb";
    //Sol
    int expectedRes=3;
    Solution sol;
    int res=sol.lengthOfLongestSubstring(input);
    EXPECT_EQ(res, expectedRes);
}
TEST(lengthOfLongestSubstring, BasicTest1) {
    // Inputs
    std::string input="bbbbbb";
    //Sol
    int expectedRes=1;
    Solution sol;
    int res=sol.lengthOfLongestSubstring(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(lengthOfLongestSubstring, BasicTest2) {
    // Inputs
    std::string input="pwwkew";
    //Sol
    int expectedRes=3;
    Solution sol;
    int res=sol.lengthOfLongestSubstring(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
