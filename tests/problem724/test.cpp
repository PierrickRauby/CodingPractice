#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>
#include <iostream>

TEST(pivotIndex, basictest) {
    // inputs
    std::vector<int> input={1,7,3,6,5,6};
    //sol
    int  expectedres=3;
    Solution sol;
    int res=sol.pivotIndex(input);
    EXPECT_EQ(res, expectedres);
}

TEST(pivotIndex, basictest1) {
    // inputs
    std::vector<int> input={-1,-1,0,1,1,0};
    //sol
    int  expectedres=5;
    Solution sol;
    int res=sol.pivotIndex(input);
    EXPECT_EQ(res, expectedres);
}

TEST(pivotIndex, basictest2) {
    // inputs
    std::vector<int> input={1,2,3};
    //sol
    int expectedres=-1;
    Solution sol;
    int res=sol.pivotIndex(input);
    EXPECT_EQ(res, expectedres);
}

TEST(pivotIndex, basictest3) {
    // inputs
    std::vector<int> input={-1,-1,-1,1,1,1};
    //sol
    int  expectedres=-1;
    Solution sol;
    int res=sol.pivotIndex(input);
    EXPECT_EQ(res, expectedres);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
