#include <gtest/gtest.h>
#include "../main.h"
#include <string>
#include <vector>

TEST(calPoints, BasicTest0) {
    // Inputs
    std::vector<std::string> input={"5","2","C","D","+"};
    int expectedRes=30;
    //Sol
    Solution sol;
    int res=sol.calPoints(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(calPoints, BasicTest1) {
    // Inputs
    std::vector<std::string> input={"5","-2","4","C","D","9","+","+"};
    int expectedRes=27;
    //Sol
    Solution sol;
    int res=sol.calPoints(input);
    EXPECT_EQ(res, expectedRes);
}

TEST(calPoints, BasicTest2) {
    // Inputs
    std::vector<std::string> input={"1","C"};
    int expectedRes=0;
    //Sol
    Solution sol;
    int res=sol.calPoints(input);
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
