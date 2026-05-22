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
   ListNode* rev(ListNode* head){
        ListNode* prev=nullptr;
       ListNode* temp=head;
       while(temp){
         ListNode* next1=temp->next;
         temp->next=prev;
         prev=temp;
         temp=next1;
       }  
       return prev;
   }

    void reorderList(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head->next;
       
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head1=rev(slow->next);
        slow->next=nullptr;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(head1 || head){
if(head){
    curr->next=head;
    head=head->next;
    curr=curr->next;
}
if(head1){
    curr->next=head1;
    head1=head1->next;
    curr=curr->next;
}
        }
        head= dummy->next;
    }
};
