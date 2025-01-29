#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

TEST(reverseString, BasicTest1)
{
    // Inputs
    std::vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> expectedRes = {'o', 'l', 'l', 'e', 'h'};
    // Sol
    Solution sol;
    sol.reverseString(input);
    EXPECT_EQ(input, expectedRes);
}

TEST(reverseString, BasicTest2)
{
    // Inputs
    std::vector<char> input = {'H', 'a', 'n', 'n', 'a', 'h'};
    std::vector<char> expectedRes = {'h', 'a', 'n', 'n', 'a', 'H'};
    // Sol
    Solution sol;
    sol.reverseString(input);
    EXPECT_EQ(input, expectedRes);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
