#include <gtest/gtest.h>
#include "solution.hpp"

TEST(gcdOfStrings, BasicTest0) {
    // Input: Linked list [1, 1, 2]
    ListNode* input = new ListNode(1, new ListNode(1, new ListNode(2)));
    
    // Expected result: Linked list [1, 2]
    ListNode* expectedRes = new ListNode(1, new ListNode(2));
    
    // Solution
    Solution sol;
    ListNode* res = sol.deleteDuplicates(input);

    EXPECT_EQ(res, res);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
