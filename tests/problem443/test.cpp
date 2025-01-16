#include <gtest/gtest.h>
#include "../main.h"

// Your test cases here
/*
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
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
