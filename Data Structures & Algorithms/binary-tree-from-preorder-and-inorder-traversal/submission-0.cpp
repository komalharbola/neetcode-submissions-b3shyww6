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
    int search(vector<int>& inorder,int val,int left,int right){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
     TreeNode* recur(vector<int>& preorder, vector<int>& inorder,int& preIndex,int left,int right){
        if(left > right) return nullptr;
        int rootVal= preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(rootVal);
        int index= search(inorder,rootVal,left,right);
        root->left=recur(preorder,inorder,preIndex,left,index-1);
        root->right=recur(preorder,inorder,preIndex,index+1,right);
        return root;
     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int preIndex=0;
         return recur(preorder,inorder,preIndex,0,inorder.size()-1);
    }
};
