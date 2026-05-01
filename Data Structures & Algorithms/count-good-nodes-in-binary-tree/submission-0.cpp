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
    void solve(TreeNode* root,int val, int&count) {
        if(!root) return;
        if(root->val>=val) {
            count++;
           
        }
        val = max(root->val,val);
        solve(root->left,val,count);
        solve(root->right,val,count);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root,root->val,count);
        return count;
    }
};
