#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(eraseOverlapIntervals, BasicTest1) {
    // Inputs
    std::vector<std::vector<int>> input={{1,2},{2,3},{3,4},{1,3}};
    //Sol
    int expectedRes=1;
    Solution sol;
    int res=sol.eraseOverlapIntervals(input);
    EXPECT_EQ(res, expectedRes);
}


TEST(eraseOverlapIntervals, BasicTest2) {
    // Inputs
    std::vector<std::vector<int>> input={{1,2},{1,2},{1,2}};
    //Sol
    int expectedRes=2;
    Solution sol;
    int res=sol.eraseOverlapIntervals(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(eraseOverlapIntervals, BasicTest3) {
    // Inputs
    std::vector<std::vector<int>> input={{1,2},{2,3}};
    //Sol
    int expectedRes=0;
    Solution sol;
    int res=sol.eraseOverlapIntervals(input);
    EXPECT_EQ(res, expectedRes);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
