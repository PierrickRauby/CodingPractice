#include "solution.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode*  Solution:: deleteDuplicates(ListNode* head) {
        ListNode* currentNode=head;
        if(currentNode==nullptr){
            return head;
        }
       while(currentNode->next!=nullptr){
        if(currentNode->val!=currentNode->next->val){
            currentNode=currentNode->next;
        }else{ //skip it
           currentNode->next=currentNode->next->next; 
        }

       }
       return head;
    };
