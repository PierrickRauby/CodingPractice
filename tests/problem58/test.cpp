#include <gtest/gtest.h>
#include "solution.hpp"
#include <string>
// Your test cases here
TEST(lengthOfLastWord, BasicTest) {
    // Inputs
    std::string inputString=" Hello World";
    int expectedRes=5;
    //Sol
    Solution sol;
    int res=sol.lengthOfLastWord(inputString);
    EXPECT_EQ(res, expectedRes);
}

TEST(lengthOfLastWord, BasicTest2) {
    // Inputs
    std::string inputString="   fly me   to   the moon  ";
    int expectedRes=4;
    //Sol
    Solution sol;
    int res=sol.lengthOfLastWord(inputString);
    EXPECT_EQ(res, expectedRes);
}

TEST(lengthOfLastWord, BasicTest3) {
    // Inputs
    std::string inputString="luffy is still joyboy";
    int expectedRes=6;
    //Sol
    Solution sol;
    int res=sol.lengthOfLastWord(inputString);
    EXPECT_EQ(res, expectedRes);
}


TEST(lengthOfLastWord, BasicTest4) {
    // Inputs
    std::string inputString="luffy is ";
    int expectedRes=2;
    //Sol
    Solution sol;
    int res=sol.lengthOfLastWord(inputString);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
