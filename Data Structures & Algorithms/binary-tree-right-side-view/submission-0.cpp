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
    void recur(TreeNode* root,int curr, int& maxi, vector<int>& ans) {
        if (root == nullptr) return;
        if(curr>maxi){
            ans.push_back(root->val);
            maxi=curr;
        }
      
        recur(root->right,curr+1,maxi, ans);
        recur(root->left,curr+1,maxi, ans);
    }

   public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        int maxi=-1;
        vector<int> ans;
       
        recur(root,0,maxi, ans);
        return ans;
    }
};
