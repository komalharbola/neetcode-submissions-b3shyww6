class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if we have k nodes
        ListNode* check = head;
        for(int i = 0; i < k; i++) {
            if(!check) return head;
            check = check->next;
        }
        
        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for(int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Recursively reverse remaining groups
        head->next = reverseKGroup(curr, k);
        
        return prev;
    }
};