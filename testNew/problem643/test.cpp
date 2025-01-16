#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(findMaxAverage, BaseTest) {
    std::vector<int>nums{1,12,-5,-6,50,3};
    int k{4};
    Solution sol;
    double expected=12.75000;
    double res=sol.findMaxAverage(nums,k);
    EXPECT_EQ(res,expected);
}

TEST(findMaxAverage, BaseTest1) {
    std::vector<int>nums{5};
    int k{1};
    Solution sol;
    double expected=5.00000;
    double res=sol.findMaxAverage(nums,k);
    EXPECT_EQ(res,expected);
}

TEST(findMaxAverage, BaseTest2) {
    std::vector<int>nums{-1};
    int k{1};
    Solution sol;
    double expected=-1.00000;
    double res=sol.findMaxAverage(nums,k);
    EXPECT_EQ(res,expected);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
