
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
// function to serialize a tree.
class Codec {
   public:
    string serialize(TreeNode* root) {
       string ans="";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // If curr node is null,
            // append -1 to result.
            if (curr == nullptr) {
                ans +="null,";
                continue;
            }

            // else push its value into
            // result and push left and right
            // child nodes into queue.
            ans += to_string(curr->val)+",";

            q.push(curr->left);
            q.push(curr->right);
        }

        return ans;
    }

    //  function to deserialize a tree.
    TreeNode* deserialize(string ans) {
        vector<string> arr;
        string s="";
        for(auto c :ans){
if(c==','){
    arr.push_back(s);
    s="";
}
else{
s += c;
}
        }
        if (arr[0] == "null") return nullptr;

        // create root node and push
        // it into queue
        TreeNode* root = new TreeNode(stoi(arr[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // If left node is not null
            if (arr[i] != "null") {
                TreeNode* left = new TreeNode(stoi(arr[i]));
                curr->left = left;
                q.push(left);
            }
            i++;

            // If right node is not null
            if (arr[i] != "null") {
                TreeNode* right = new TreeNode(stoi(arr[i]));
                curr->right = right;
                q.push(right);
            }
            i++;
        }

        return root;
    }
};