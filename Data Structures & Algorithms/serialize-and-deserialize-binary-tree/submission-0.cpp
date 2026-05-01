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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "#";
        }
        string curr = to_string(root->val);
        return curr + ","+ serialize(root->left)+","+serialize(root->right)+",";
    }

    TreeNode* solve(vector<string> data,int& idx, int n) {
        if(idx==n || data[idx]=="#") {
            idx++;
            return NULL;
        }
        TreeNode* curr = new TreeNode(stoi(data[idx++]));
        curr->left = solve(data,idx,n);
        curr->right = solve(data,idx,n);
        return curr;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        int n = data.size();
        stringstream ss(data);
        string temp;
        vector<string>nodes;
        while(getline(ss,temp,',')) {
            if(temp!="")
            nodes.push_back(temp);
        }
        return solve(nodes,idx,n);
    }
};
