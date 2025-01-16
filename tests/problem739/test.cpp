#include <gtest/gtest.h>
#include "../main.h"
#include <vector>

TEST(dailyTemperatures, BasicTest0) {
    // Inputs
    std::vector<int> input={73,74,75,71,69,72,76,73};
    std::vector<int> expectedRes={1,1,4,2,1,1,0,0};
    //Sol
    Solution sol;
    std::vector<int> res=sol.dailyTemperatures(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
