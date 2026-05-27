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
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int lH=height(root->left);
        int lR=height(root->right);
        return max(lH,lR)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int lH=height(root->left);
        int lR=height(root->right);
        if(abs(lH-lR) >1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};
