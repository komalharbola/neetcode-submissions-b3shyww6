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
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* dummy=new ListNode(-1); 
       ListNode* temp=dummy; 
       while(list1 && list2){
        if(list1->val <= list2->val){
            temp->next=list1;
            list1=list1->next;
        }
        else{
  temp->next=list2;
  list2=list2->next;
           
       }
       temp=temp->next;
       }
       if(list1){
        temp->next=list1;
      
        
       }
       if(list2){
        temp->next=list2;
        
       }
       return dummy->next; 
    }
    ListNode* recur(int i,int j,vector<ListNode*> arr){
        if(i==j) return arr[i];
        int mid= i+(j-i)/2;
        ListNode* head1= recur(i,mid,arr);
        ListNode* head2=recur(mid+1,j,arr);
        ListNode* head = mergeTwoLists(head1,head2);
        return head;

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()== 0) return nullptr;
        return recur(0,lists.size()-1,lists);
    }
};
