#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(merge, BasicTest) {
    // Inputs
    std::vector<int> nums1={1,2,3,0,0,0};
    std::vector<int> nums2={2,5,7};
    std::vector<int> expectedRes={1,2,2,3,5,7};
    int m=3;
    int n=3;
    //Sol
    Solution sol;
    sol.merge(nums1,m,nums2,n);
    EXPECT_EQ(nums1, expectedRes);
}

TEST(merge, BasicTest1) {
    // Inputs
    std::vector<int> nums1={0,0,0};
    std::vector<int> nums2={2,5,7};
    std::vector<int> expectedRes={2,5,7};
    int m=0;
    int n=3;
    //Sol
    Solution sol;
    sol.merge(nums1,m,nums2,n);
    EXPECT_EQ(nums1, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
