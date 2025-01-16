#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(kidsWithCandies, BasicTest) {
    std::vector<int> candies={2,3,5,1,3};
    int extraCandies=3;
    //Sol
    Solution sol;
    std::vector<bool> expectedRes={true,true,true,false,true};
    std::vector<bool>  res=sol.kidsWithCandies(candies,extraCandies);
    EXPECT_EQ(res, expectedRes);
}

TEST(kidsWithCandies, BasicTest1) {
    std::vector<int> candies={4,2,1,1,2};
    int extraCandies=1;
    //Sol
    Solution sol;
    std::vector<bool> expectedRes={true,false,false,false,false} ;
    std::vector<bool> res=sol.kidsWithCandies(candies,extraCandies);
    EXPECT_EQ(res, expectedRes);
}




TEST(kidsWithCandies, BasicTest2) {
    std::vector<int> candies={12,1,12};
    int extraCandies=10;
    //Sol
    Solution sol;
    std::vector<bool> expectedRes={true,false,true} ;
    std::vector<bool> res=sol.kidsWithCandies(candies,extraCandies);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
