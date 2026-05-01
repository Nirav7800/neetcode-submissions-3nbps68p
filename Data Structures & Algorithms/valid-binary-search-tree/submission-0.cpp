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
    void solve(TreeNode* root, TreeNode*& prev, bool&ans) {
        if(!root) return ;
        solve(root->left,prev,ans);
        if(prev && root->val <= prev->val) {
            ans = false;
            return;
        }
        prev = root;
        solve(root->right,prev,ans);

    }
    bool isValidBST(TreeNode* root) {
       TreeNode* prev = NULL;
       bool ans = 1;
       solve(root,prev,ans);
       return ans;

    }
};
