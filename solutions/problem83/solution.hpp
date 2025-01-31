#ifndef PROBLEM83_MAIN_H
#define PROBLEM83_MAIN_H


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode*  deleteDuplicates(ListNode* head) ;
};

#endif // PROBLEM83_MAIN_H
