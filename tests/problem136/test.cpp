#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(singleNumber, BasicTest1) {
    // Inputs
    std::vector<int> input{2,2,1};
    int expectedRes=1;
    //Sol
    Solution sol;
    int res=sol.singleNumber(input);
    EXPECT_EQ(res, expectedRes);
}
TEST(singleNumber, BasicTest2) {
    // Inputs
    std::vector<int> input{1};
    int expectedRes=1;
    //Sol
    Solution sol;
    int res=sol.singleNumber(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(singleNumber, BasicTest3) {
    // Inputs
    std::vector<int> input{4,1,2,1,2};
    int expectedRes=4;
    //Sol
    Solution sol;
    int res=sol.singleNumber(input);
    EXPECT_EQ(res, expectedRes);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
