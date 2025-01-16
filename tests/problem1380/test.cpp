#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(luckyNumbers, BasicTest) {
    // Inputs
    std::vector<int> expectedRes={15};
    std::vector<std::vector<int>> inputMatrix;
    inputMatrix.push_back({3,7,8});
    inputMatrix.push_back({9,11,13});
    inputMatrix.push_back({15,16,17});
    //Sol
    Solution sol;
    std::vector<int> res=sol.luckyNumbers(inputMatrix);
    EXPECT_EQ(res, expectedRes);
}


TEST(luckyNumbers, BasicTest1) {
    // Inputs
    std::vector<int> expectedRes={12};
    std::vector<std::vector<int>> inputMatrix;
    inputMatrix.push_back({1,10,4,2});
    inputMatrix.push_back({9,3,8,7});
    inputMatrix.push_back({15,16,17,12});
    //Sol
    Solution sol;
    std::vector<int> res=sol.luckyNumbers(inputMatrix);
    EXPECT_EQ(res, expectedRes);
}

TEST(luckyNumbers, BasicTest2) {
    // Inputs
    std::vector<int> expectedRes={7};
    std::vector<std::vector<int>> inputMatrix;
    inputMatrix.push_back({7,8});
    inputMatrix.push_back({1,2});
    //Sol
    Solution sol;
    std::vector<int> res=sol.luckyNumbers(inputMatrix);
    EXPECT_EQ(res, expectedRes);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
