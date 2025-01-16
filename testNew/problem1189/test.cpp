#include <gtest/gtest.h>
#include "../main.h"

TEST(maxNumberOfBalloons, BasicTest) {
    // Inputs
    std::string str1="nlaebolko";
    int expectedRes=1;
    //Sol
    Solution sol;
    int res=sol.maxNumberOfBalloons(str1);
    EXPECT_EQ(res, expectedRes);
}

TEST(maxNumberOfBalloons, BasicTest1) {
    // Inputs
    std::string str1="loonbalxballpoon";
    int expectedRes=2;
    //Sol
    Solution sol;
    int res=sol.maxNumberOfBalloons(str1);
    EXPECT_EQ(res, expectedRes);
}

TEST(maxNumberOfBalloons, BasicTest2) {
    // Inputs
    std::string str1="leetcode";
    int expectedRes=0;
    //Sol
    Solution sol;
    int res=sol.maxNumberOfBalloons(str1);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
