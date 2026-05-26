class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if we have k nodes
        ListNode* check=head;
        for(int i=0;i<k;i++){
            if(check == nullptr) return head;
            check=check->next;
        }
      ListNode* curr=head;
      ListNode* prev=nullptr;
      for(int i=0;i<k;i++){
         ListNode* nextNode=curr->next;
         curr->next=prev;
         prev=curr;
         curr=nextNode;
      }
      head->next= reverseKGroup(curr,k);
      return prev;
    }
};