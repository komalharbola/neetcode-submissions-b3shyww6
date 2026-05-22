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
int getLen(ListNode* head){
    ListNode* temp=head;
    int count=0;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=getLen(head);
        int i=count-n;
        if(i==0) return head->next;
        ListNode* temp=head;
        while(i>1){
            temp=temp->next;
            i--;
        }
        temp->next=temp->next->next;
return head;
    }
};
