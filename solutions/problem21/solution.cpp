#include "solution.hpp"



    ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 2 pointers for the heads 
        ListNode* head=new ListNode();
        ListNode* tail=head;
        //iterate over the list

        while(list1!=nullptr & list2!=nullptr){
           if(list1->val<list2->val){
            tail->next=list1;
            list1=list1->next;

           }else{
            tail->next=list2;
            list2=list2->next;
           }
        tail=tail->next;
        }
        tail->next= list1==nullptr ? list2:list1;
        return head->next;
    }
