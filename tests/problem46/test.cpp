#include <gtest/gtest.h>
#include "solution.hpp"
#include <set>
#include <vector>

TEST(permute, BasicTest1) {
    std::vector<int> input={1,2,3};
std::vector<std::vector<int>>expectedRes={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    //Sol
    Solution sol;
    std::vector<std::vector<int>> res=sol.permute(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(permute, BasicTest2) {
    std::vector<int> input={0,1};
    std::vector<std::vector<int>> expectedRes = {{0, 1}, {1, 0}};
    //Sol
    Solution sol;
    std::vector<std::vector<int>> res=sol.permute(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(permute, BasicTest3) {
    std::vector<int> input={1};
    std::vector<std::vector<int>> expectedRes = {{1}};
    //Sol
    Solution sol;
    std::vector<std::vector<int>> res=sol.permute(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
