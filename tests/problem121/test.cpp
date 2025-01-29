#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

TEST(maxProfit, BasicTest) {
    // Inputs
    std::vector<int> stockPrices{7,1,5,3,6,4};
    //Sol
    Solution sol;
    int res=sol.maxProfit(stockPrices);
    int expectedRes=5;
    EXPECT_EQ(res, expectedRes);
}

TEST(maxProfit, BasicTest1) {
    // Inputs
    std::vector<int> stockPrices{7,6,4,3,1};
    //Sol
    Solution sol;
    int res=sol.maxProfit(stockPrices);
    int expectedRes=0;
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
