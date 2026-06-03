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
    int recur(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int l = max(0, recur(root->left, res));
        int r = max(0, recur(root->right, res));
        res = max(res, l + r + root->val);
        return root->val + max(l, r);
    }

   public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        recur(root, res);
        return res;
    }
};
