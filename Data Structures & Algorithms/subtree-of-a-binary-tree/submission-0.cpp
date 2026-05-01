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
    bool solve(TreeNode* root, TreeNode* subRoot,bool taken) {
      if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        bool ans = false;
        if(taken) {
            if(root->val==subRoot->val) {
                ans = solve(root->left,subRoot->left,taken)&&solve(root->right,subRoot->right,taken);
            }
        } else {
            if(root->val==subRoot->val) {
                 ans = solve(root->left,subRoot->left,true)&&solve(root->right,subRoot->right,true);
            } 
            ans|=solve(root->left,subRoot,false)||solve(root->right,subRoot,false);
        }
        return ans;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool taken = false;
        return solve(root,subRoot,taken);
    }
};
