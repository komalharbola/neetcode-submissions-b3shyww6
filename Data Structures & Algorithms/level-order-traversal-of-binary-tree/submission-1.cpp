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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*>q;
        vector<vector<int>> ans;
       
        q.push(root);
        int level=0;
        while(!q.empty()){
          int len= q.size();
          ans.push_back({});
          for(int i=0;i<len;i++){
              TreeNode* n=q.front();
              q.pop();
              ans[level].push_back(n->val);
              if(n->left) q.push(n->left);
              if(n->right) q.push(n->right);
          }
         
        level++;
      
        }
        return ans;
    }
};
