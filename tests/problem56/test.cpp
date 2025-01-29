#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

TEST(merge, BasicTest) {
    // Inputs
    std::vector<std::vector<int>> input = {{1, 3},
                                           {2, 6},
                                           {8, 10},
                                           {15, 18}};
    std::vector<std::vector<int>>
        expectedRes = {{1, 6},
                       {8, 10},
                       {15, 18}};
    // Sol
    Solution sol;
    std::vector<std::vector<int>> res=sol.merge(input);
    EXPECT_EQ(res, expectedRes);
}
TEST(merge, BasicTest1) {
    // Inputs
    std::vector<std::vector<int>> input = {{1, 4},
                                           {4, 5}};
    std::vector<std::vector<int>>
        expectedRes = {{1, 5}};
    // Sol
    Solution sol;
    std::vector<std::vector<int>> res=sol.merge(input);
    EXPECT_EQ(res, expectedRes);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
