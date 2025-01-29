#include <gtest/gtest.h>
#include "solution.hpp"
#include <vector>

std::vector<int> testMinStack(){
    std::vector<int> res;
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    res.push_back(minStack->getMin()); // return -3
    minStack->pop();
    res.push_back(minStack->top());    // return 0
    res.push_back(minStack->getMin()); // return -2
    return res;
}

TEST(MinStack, BasicTest0) {
    std::vector<int> res=testMinStack();
    std::vector<int> expectedRes={-3,0,-2};
    EXPECT_EQ(res, expectedRes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
