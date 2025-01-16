#include <gtest/gtest.h>
#include "../main.h"

void insertAtEnd(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool areListsEqual(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}


TEST(mergeTwoLists, BasicTest) {
    // Inputs

      ListNode* list1 = nullptr;
      ListNode* list2 = nullptr;
      ListNode* expectedRes = nullptr;

    // Inserting elements into the linked list
    insertAtEnd(list1, 1);
    insertAtEnd(list1, 2);
    insertAtEnd(list1, 4);

    insertAtEnd(list2, 1);
    insertAtEnd(list2, 3);
    insertAtEnd(list2, 4);

    insertAtEnd(expectedRes, 1);
    insertAtEnd(expectedRes, 1);
    insertAtEnd(expectedRes, 2);
    insertAtEnd(expectedRes, 3);
    insertAtEnd(expectedRes, 4);
    insertAtEnd(expectedRes, 4);

    //Sol
    Solution sol;
    ListNode* res=sol.mergeTwoLists(list1,list2);
    EXPECT_TRUE(areListsEqual(res, expectedRes));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
