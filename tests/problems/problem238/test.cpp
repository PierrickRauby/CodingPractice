#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>


TEST(productExceptSelf, BasicTest1) {
    // Inputs
    std::vector<int> input={-1,1,0,-3,3};
    std::vector<int> expectedRes={0,0,9,0,0};
    //Sol
    Solution sol;
    std::vector<int> res=sol.productExceptSelf(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(productExceptSelf, BasicTest) {
    // Inputs
    std::vector<int> input={1,2,3,4};
    std::vector<int> expectedRes={24,12,8,6};
    //Sol
    Solution sol;
    std::vector<int> res=sol.productExceptSelf(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
