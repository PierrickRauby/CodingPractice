#include <gtest/gtest.h>
#include "../main.h"

#include <string>

TEST(numJewelsInStones, BasicTest) {
    // Inputs
    std::string jewels="z";
    std::string stones="ZZ";
    int expectedRes=0;
    //Sol
    Solution sol;
    int res=sol.numJewelsInStones(jewels,stones);
    EXPECT_EQ(res, expectedRes);
}

TEST(numJewelsInStones, BasicTest1) {
    // Inputs
    std::string jewels="aA";
    std::string stones="aAAbbbb";
    int expectedRes=3;
    //Sol
    Solution sol;
    int res=sol.numJewelsInStones(jewels,stones);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
