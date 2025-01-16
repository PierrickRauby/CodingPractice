#include <gtest/gtest.h>
#include "../main.h"
#include <string>

TEST(isAnagram, BasicTest1) {
    // Inputs
    std::string str1="anagram";
    std::string str2="nagaram";
    bool expectedRes=true;
    //Sol
    Solution sol;
    bool res=sol.isAnagram(str1,str2);
    EXPECT_EQ(res, expectedRes);
}

TEST(isAnagram, BasicTest2) {
    // Inputs
    std::string str1="car";
    std::string str2="rat";
    bool expectedRes=false;
    //Sol
    Solution sol;
    bool res=sol.isAnagram(str1,str2);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}