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
    int recur(TreeNode* root){
        if(root == nullptr) return 0;
        int lH=recur(root->left);
        int lR=recur(root->right);
        if(lH == -1 || lR == -1 || abs(lH-lR) >1) return -1;
        return max(lH,lR)+1;
    }
public:
    
    bool isBalanced(TreeNode* root) {
        return recur(root)>=0;
    }
};
