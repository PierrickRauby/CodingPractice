#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

TEST(gcdOfStrings, BasicTest) {
    // Inputs
    int input{2};
    std::vector<int> expectedRes{0,1,1};
    //Sol
    Solution sol;
    std::vector<int> res=sol.countBits(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(gcdOfStrings, BasicTest2) {
    // Inputs
    int input{5};
    std::vector<int> expectedRes{0,1,1,2,1,2};
    //Sol
    Solution sol;
    std::vector<int> res=sol.countBits(input);
    EXPECT_EQ(res, expectedRes);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
