/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int cnt=0;
    void recur(TreeNode* root ,int mx){
         if(root==nullptr) return;
         if(mx<= root->val)cnt++;
         recur(root->left,max(mx,root->val));
         recur(root->right,max(mx,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        recur(root,INT_MIN);
        return cnt;
    }
};
