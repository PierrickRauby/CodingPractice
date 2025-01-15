#include <gtest/gtest.h>
#include "main.h"
#include <vector>
#include <unordered_map>

TEST(twoSum,BasicTest ) {
    std::vector<int> nums={2,7,11,15};
    int target=9;
    Solution sol;
    std::vector<int> expectedRes={0,1};
    std::vector<int> res=sol.twoSum(nums,target);
    EXPECT_EQ(res,expectedRes);
}

TEST(twoSum,BasicTest2) {
    std::vector<int> nums={3,2,4};
    int target=6;
    Solution sol;
    std::vector<int> expectedRes={1,2};
    std::vector<int> res=sol.twoSum(nums,target);
    EXPECT_EQ(res,expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
