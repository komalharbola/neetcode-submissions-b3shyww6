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
  
     TreeNode* recur(unordered_map<int,int>& mp ,vector<int>& preorder, vector<int>& inorder,int& preIndex,int left,int right){
        if(left > right) return nullptr;
        int rootVal= preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(rootVal);
        int index= mp[rootVal];
        root->left=recur(mp,preorder,inorder,preIndex,left,index-1);
        root->right=recur(mp,preorder,inorder,preIndex,index+1,right);
        return root;
     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int preIndex=0;
         unordered_map<int,int>mp;
         for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
         }
         return recur(mp,preorder,inorder,preIndex,0,inorder.size()-1);
    }
};
