#include <gtest/gtest.h>
#include "solution.hpp"

TEST(gcdOfStrings, BasicTest0) {
    // Inputs
    std::string input="leet**cod*e";
    std::string expectedRes="lecoe";
    //Sol
    Solution sol;
    std::string res=sol.removeStars(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(gcdOfStrings, BasicTest1) {
    // Inputs
    std::string input="erase*****";
    std::string expectedRes="";
    //Sol
    Solution sol;
    std::string res=sol.removeStars(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
