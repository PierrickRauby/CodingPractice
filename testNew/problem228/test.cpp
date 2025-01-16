#include <gtest/gtest.h>
#include "../main.h"
#include <string>
#include <vector>

TEST(summaryRanges, BasicTest1) {
    // Inputs
    std::vector<int> input={0,1,2,4,5,7};
    std::vector<std::string> expectedRes={"0->2","4->5","7"};
    //Sol
    Solution sol;
    std::vector<std::string> res=sol.summaryRanges(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(summaryRanges, BasicTest2) {
    // Inputs
    std::vector<int> input={0,2,3,4,6,8,9};
    std::vector<std::string> expectedRes={"0","2->4","6","8->9"};
    //Sol
    Solution sol;
    std::vector<std::string> res=sol.summaryRanges(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(summaryRanges, BasicTest3) {
    // Inputs
    std::vector<int> input={-1};
    std::vector<std::string> expectedRes={"-1"};
    //Sol
    Solution sol;
    std::vector<std::string> res=sol.summaryRanges(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(summaryRanges, BasicTest4) {
    // Inputs
    std::vector<int> input={0,1};
    std::vector<std::string> expectedRes={"0->1"};
    //Sol
    Solution sol;
    std::vector<std::string> res=sol.summaryRanges(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(summaryRanges, BasicTest5) {
    // Inputs
    std::vector<int> input={0,2};
    std::vector<std::string> expectedRes={"0","2"};
    //Sol
    Solution sol;
    std::vector<std::string> res=sol.summaryRanges(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
