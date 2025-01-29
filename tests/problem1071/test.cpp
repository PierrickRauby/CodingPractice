#include <gtest/gtest.h>
#include "solution.hpp"
#include <string>

// Your test cases here

TEST(gcdOfStrings, BasicTest) {
    // Inputs
    std::string str1="ABCABC";
    std::string str2="ABC";
    std::string expectedRes="ABC";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}
TEST(gcdOfStrings, BasicTest1) {
    // Inputs
    std::string str1="ABABAB";
    std::string str2="AB";
    std::string expectedRes="AB";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}

TEST(gcdOfStrings, gcdTest1) {
    // Inputs
    std::string str1="ABABAB";
    std::string str2="ABAB";
    std::string expectedRes="AB";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}

TEST(gcdOfStrings, gcdTest2) {
    // Inputs
    std::string str1="ABABAB";
    std::string str2="ABC";
    std::string expectedRes="";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}

TEST(gcdOfStrings, BasicTest2) {
    // Inputs
    std::string str1="LEET";
    std::string str2="CODE";
    std::string expectedRes="";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}
TEST(gcdOfStrings, BasicTest3) {
    // Inputs
    std::string str1="";
    std::string str2="CODE";
    std::string expectedRes="";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}
TEST(gcdOfStrings, BasicTest4) {
    // Inputs
    std::string str1="LEET";
    std::string str2="";
    std::string expectedRes="";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}
TEST(gcdOfStrings, BasicTest5) {
    // Inputs
    std::string str1="ABABAB";
    std::string str2="AA";
    std::string expectedRes="";
    //Sol
    Solution sol;
    std::string res=sol.gcdOfStrings(str1,str2);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
