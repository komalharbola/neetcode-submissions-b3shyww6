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

class Codec {
    private:
    void code(TreeNode* root , string& res){
        if(root == nullptr) {
            res += "null,";
            return;
        }
        res += to_string(root->val)+",";
        code(root->left,res);
        code(root->right,res);
    }
    TreeNode* decode(vector<string>& tokens ,int& i){
        if(tokens[i]=="null"){
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(tokens[i]));
        i++;
        root->left = decode(tokens,i);
        root->right = decode(tokens,i);
        return root;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        code(root,res);
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string s="";
        for(auto c:data){
     if(c==','){
        tokens.push_back(s);
        s="";
        continue;
     }
     s += c;
        }
        int i =0;
      return  decode(tokens,i);
    }
};
