#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

TEST(canPlaceFlowers, BasicTest) {
    // Inputs
    std::vector<int> input={1,0,0,0,1};
    int flowerNum=1;
    //Sol
    bool expectedRes=true;
    Solution sol;
    bool res=sol.canPlaceFlowers(input,flowerNum);
    EXPECT_EQ(res, expectedRes);
}

TEST(canPlaceFlowers, BasicTest1) {
    // Inputs
    std::vector<int> input={1,0,0,0,1};
    int flowerNum=2;
    //Sol
    bool expectedRes=false;
    Solution sol;
    bool res=sol.canPlaceFlowers(input,flowerNum);
    EXPECT_EQ(res, expectedRes);
}

TEST(canPlaceFlowers, BasicTest2) {
    // Inputs
    std::vector<int> input={1,0,0,0,0,0,1};
    int flowerNum=2;
    //Sol
    bool expectedRes=true;
    Solution sol;
    bool res=sol.canPlaceFlowers(input,flowerNum);
    EXPECT_EQ(res, expectedRes);
}


TEST(canPlaceFlowers, BasicTest3) {
    // Inputs
    std::vector<int> input={0,0,1,0,1};
    int flowerNum=1;
    //Sol
    bool expectedRes=true;
    Solution sol;
    bool res=sol.canPlaceFlowers(input,flowerNum);
    EXPECT_EQ(res, expectedRes);
}


TEST(canPlaceFlowers, BasicTest4) {
    // Inputs
    std::vector<int> input={1,0,0,0,0,1};
    int flowerNum=1;
    //Sol
    bool expectedRes=true;
    Solution sol;
    bool res=sol.canPlaceFlowers(input,flowerNum);
    EXPECT_EQ(res, expectedRes);
}


TEST(canPlaceFlowers, BasicTest5) {
    // Inputs
    std::vector<int> input={1,0,0,0,0,1};
    int flowerNum=2;
    //Sol
    bool expectedRes=false;
    Solution sol;
    bool res=sol.canPlaceFlowers(input,flowerNum);
    EXPECT_EQ(res, expectedRes);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
