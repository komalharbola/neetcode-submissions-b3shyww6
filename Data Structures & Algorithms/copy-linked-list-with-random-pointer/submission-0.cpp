/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node*,Node*> mp;
        Node* dummy=new Node(0);
     
        while(temp){
          mp[temp]=new Node(temp->val);
          temp=temp->next;

        }
        temp=head;
        Node* head1=new Node(0);
        while(temp){
          head1->next=mp[temp];
          head1->next->random=mp[temp->random];
          head1=head1->next;
          temp=temp->next;
          

        }
        return mp[head];
    }
};
