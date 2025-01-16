#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(sortedSquares, BasicTest1) {
    // Inputs
    std::vector<int> input={-4,-1,0,3,10};
    std::vector<int> expectedRes={0,1,9,16,100};
    //Sol
    Solution sol;
    std::vector<int> res=sol.sortedSquares(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(sortedSquares, BasicTest2) {
    // Inputs
    std::vector<int> input={-7,-3,2,3,11};
    std::vector<int> expectedRes={4,9,9,49,121};
    //Sol
    Solution sol;
    std::vector<int> res=sol.sortedSquares(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
