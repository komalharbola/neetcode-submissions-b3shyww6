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
    bool helper(TreeNode* root , long long mx ,long long mn){
        if (root == nullptr) return true;
        if(root->val >mx || root->val  <mn) return false;
        return helper(root->left,(long long)root->val-1,mn) &&helper(root->right,mx,(long long)root->val+1);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,INT_MAX,INT_MIN);
    }
};
