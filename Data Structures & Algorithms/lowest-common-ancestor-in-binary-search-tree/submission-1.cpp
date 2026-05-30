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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        while (root != nullptr) {
      
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->val > n1->val && root->val> n2->val)
            root = root->left;

        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->val < n1->val && root->val < n2->val)
            root = root->right;
        
        // Else Ancestor is found
        else
            break;
    }
return root;
    }
};
