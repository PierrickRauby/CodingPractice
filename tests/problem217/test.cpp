#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

TEST(containsDuplicate, BasicTest1) {
    // Inputs
    std::vector<int> input={1,2,3,1};
    bool expectedRes = true;
    //Sol
    Solution sol;
    bool res=sol.containsDuplicate(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(containsDuplicate, BasicTest2) {
    // Inputs
    std::vector<int> input={1,2,3,4};
    bool expectedRes = false;
    //Sol
    Solution sol;
    bool res=sol.containsDuplicate(input);
    EXPECT_EQ(res, expectedRes);
}
TEST(containsDuplicate, BasicTest3) {
    // Inputs
    std::vector<int> input={1,1,1,3,3,4,3,2,4,2};
    bool expectedRes = true;
    //Sol
    Solution sol;
    bool res=sol.containsDuplicate(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
