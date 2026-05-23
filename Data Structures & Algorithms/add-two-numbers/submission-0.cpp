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
 ListNode* reverseList(ListNode* head) {
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
    
     ListNode* ans=   new ListNode(-1);
     ListNode* temp= ans;
     int carry=0;
     while(l1 || l2 || carry){
        int sum=carry;
        if(l1){
            sum +=l1->val ;
            l1=l1->next;
          
            
        }
     if(l2){
sum +=l2->val;
l2=l2->next;
        }
      
    
                
           
            
            temp->next= new ListNode(sum%10);
            carry=sum/10;
            temp=temp->next;
        
     }
    
     
       return ans->next;

    }
};
