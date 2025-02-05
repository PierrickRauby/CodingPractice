#include <gtest/gtest.h>
#include "solution.hpp"

TEST(MoveZeroesTest, BasicTest) {
    Solution sol;
    std::vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    std::vector<int> expected = {1, 3, 12, 0, 0};
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroesTest, AllZeros) {
    Solution sol;
    std::vector<int> nums = {0, 0, 0, 0};
    sol.moveZeroes(nums);
    std::vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroesTest, NoZeros) {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4};
    sol.moveZeroes(nums);
    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(nums, expected);
}

TEST(MoveZeroesTest, Mixed) {
    Solution sol;
    std::vector<int> nums = {1, 0, 2, 0, 3, 0};
    sol.moveZeroes(nums);
    std::vector<int> expected = {1, 2, 3, 0, 0, 0};
    EXPECT_EQ(nums, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
