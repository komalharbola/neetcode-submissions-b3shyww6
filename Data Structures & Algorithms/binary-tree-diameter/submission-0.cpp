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
        int height(TreeNode* root){
            if(root== nullptr)return 0;
            int lH=height(root->left);
            int rH=height(root->right);
            return max(lH,rH)+1;
        }
    public:

        int diameterOfBinaryTree(TreeNode* root) {
            if(root== nullptr)return 0;
            int lH=height(root->left);
            int rH=height(root->right);
            int lD= diameterOfBinaryTree(root->left);
            int rD= diameterOfBinaryTree(root->right);
            return max({lH+rH,lD,rD});
        }
};
