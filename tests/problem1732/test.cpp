#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

TEST(largestAltitude, BasicTest) {
    // Inputs
    std::vector<int> input{-5,1,5,0,-7};
    int expectedRes=1;
    //Sol
    Solution sol;
    int res=sol.largestAltitude(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(largestAltitude, BasicTest1) {
    // Inputs
    std::vector<int> input{-4,-3,-2,-1,4,3,2};
    int expectedRes=0;
    //Sol
    Solution sol;
    int res=sol.largestAltitude(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
