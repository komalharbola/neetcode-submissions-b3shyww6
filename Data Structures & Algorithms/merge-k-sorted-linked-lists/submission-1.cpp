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
private:
ListNode* getMini(vector<ListNode*>& lists){
    ListNode* mini=nullptr;
    int index=-1;
    for(int i=0;i<lists.size();i++){
        if(lists[i]== nullptr) continue;
        if(mini ==nullptr || mini->val > lists[i]->val){
            mini=lists[i];
            index=i;
        }
    }
    if(index != -1) lists[index]=lists[index]->next;
    return mini;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode* dummy = new ListNode(-1);
       ListNode* temp=dummy;
       while(temp != nullptr){
            temp->next = getMini(lists);
            temp=temp->next;
       } 
       return dummy->next;
    }
};
