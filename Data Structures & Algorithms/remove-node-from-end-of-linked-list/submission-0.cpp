
class Solution {
public:
ListNode* reverseList(ListNode* head) {
       ListNode *curr=head,*prev=NULL, *next=NULL;
       while(curr!=NULL)
       {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

       }
       return prev;
    }
    ListNode* removeNfromFront(ListNode* head, int x)
    {
        if (x == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* temp=head;
        ListNode *prev = nullptr;
        for (int i = 1; i < x; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;

        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      head = reverseList(head);
      head = removeNfromFront(head,n);
      head = reverseList(head);
      return head; 
    }
};
