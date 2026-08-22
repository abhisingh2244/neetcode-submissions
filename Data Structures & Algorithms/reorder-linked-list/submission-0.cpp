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

class Solution {
public:
    void reorderList(ListNode* head) {
     ListNode* slow=head,*fast=head;
     while(fast && fast->next)
     {
        slow=slow->next;
        fast=fast->next->next;
     }  
     //Breaking LinkedList in two half
     ListNode* second=slow->next;
     slow->next=nullptr;
     //Reverse Linked list
     ListNode* prev=nullptr;
     while(second)
     {
        ListNode* next=second->next;
        second->next=prev;
        prev=second;
        second=next;
     }
     second=prev;
     //Merge these two list
     ListNode * first=head;
     while(second)
     {
        ListNode* temp2=second->next;
        ListNode* temp1=first->next;first->next=second;
        second->next=temp1;
        first=temp1;
        second=temp2;


     }
    }
};
