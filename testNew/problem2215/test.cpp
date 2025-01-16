#include <gtest/gtest.h>
#include "../main.h"
#include <vector>
#include <set>

TEST(findDifference, BasicTest1) {
    // Inputs
    std::vector<int> nums1={1,2,3};
    std::vector<int> nums2={2,4,6};
    std::vector<std::vector<int>> expectedRes={{1,3},{4,6}};
    //Sol

    Solution sol;
    std::vector<std::vector<int>> res=sol.findDifference(nums1,nums2);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
