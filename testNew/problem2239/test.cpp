#include <gtest/gtest.h>
#include "../main.h"

TEST(gcdOfStrings, BasicTest) {
    // Inputs
    std::vector<int> nums{-4,-2,1,4,8};
    //Sol
    Solution sol;
    int expectedRes=1;
    int res=sol.findClosestNumber(nums);
    EXPECT_EQ(res, expectedRes);
}

TEST(gcdOfStrings, BasicTest1) {
    // Inputs
    std::vector<int> nums{2,-1,1};
    //Sol
    Solution sol;
    int expectedRes=1;
    int res=sol.findClosestNumber(nums);
    EXPECT_EQ(res, expectedRes);
}

TEST(gcdOfStrings, BasicTest2) {
    // Inputs
    std::vector<int> nums{0};
    //Sol
    Solution sol;
    int expectedRes=0;
    int res=sol.findClosestNumber(nums);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
