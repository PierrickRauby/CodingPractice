#include <gtest/gtest.h>
#include "../main.h"
#include<map>
#include<string>

TEST(romanToInt, BasicTest1) {
    // Inputs
    std::string input="III";
    int expectedRes=3;
    //Sol
    Solution sol;
    int res=sol.romanToInt(input);
    EXPECT_EQ(res, expectedRes);
}


TEST(romanToInt, BasicTest2) {
    // Inputs
    std::string input="LVIII";
    int expectedRes=58;
    //Sol
    Solution sol;
    int res=sol.romanToInt(input);
    EXPECT_EQ(res, expectedRes);
}


TEST(romanToInt, BasicTest3) {
    // Inputs
    std::string input="MCMXCIV";
    int expectedRes=1994;
    //Sol
    Solution sol;
    int res=sol.romanToInt(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
