#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(uniqueOccurrences, BasicTest) {
    // Inputs
    std::vector<int> input={1,2,2,1,1,3};
    bool expectedRes=true;
    //Sol
    Solution sol;
    bool res=sol.uniqueOccurrences(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(uniqueOccurrences, BasicTest1) {
    // Inputs
    std::vector<int> input={1,2};
    bool expectedRes=false;
    //Sol
    Solution sol;
    bool res=sol.uniqueOccurrences(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(uniqueOccurrences, BasicTest2) {
    // Inputs
    std::vector<int> input={-3,0,1,-3,1,1,1,-3,10,0};
    bool expectedRes=true;
    //Sol
    Solution sol;
    bool res=sol.uniqueOccurrences(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
