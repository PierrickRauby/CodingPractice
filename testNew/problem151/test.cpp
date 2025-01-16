#include <gtest/gtest.h>
#include "../main.h"
#include <vector>
#include <string>
#include <iostream>

TEST(reverseWords, BasicTest) {
    // Inputs
    std::string input="the sky is blue";
    std::string expectedRes="blue is sky the";
    //Sol
    Solution sol;
    std::string res=sol.reverseWords(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(reverseWords, BasicTest1) {
    // Inputs
    std::string input="a good example";
    std::string expectedRes="example good a";
    //Sol
    Solution sol;
    std::string res=sol.reverseWords(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(reverseWords, BasicTest2) {
    // Inputs
    std::string input=" hello world";
    std::string expectedRes="world hello";
    //Sol
    Solution sol;
    std::string res=sol.reverseWords(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(reverseWords, SingleWord) {
    // Inputs
    std::string input="a";
    std::string expectedRes="a";
    //Sol
    Solution sol;
    std::string res=sol.reverseWords(input);
    EXPECT_EQ(res, expectedRes);
}
TEST(reverseWords, SingleWordLeadingSpaces) {
    // Inputs
    std::string input="    a";
    std::string expectedRes="a";
    //Sol
    Solution sol;
    std::string res=sol.reverseWords(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(reverseWords, LeadingSpacesTest) {
    // Inputs
    std::string input="    the sky is blue";
    std::string expectedRes="blue is sky the";
    //Sol
    Solution sol;
    std::string res=sol.reverseWords(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
