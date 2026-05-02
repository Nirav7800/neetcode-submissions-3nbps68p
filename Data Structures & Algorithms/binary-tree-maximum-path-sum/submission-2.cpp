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
    int solve(TreeNode* root, int&ans) {
        if(!root) return 0;
        int lval = solve(root->left,ans);
        int rval = solve(root->right,ans);
        ans = max(max(root->val,ans),max(rval+lval+root->val,max(rval+root->val,lval+root->val)));
        return max(root->val,root->val+max(rval,lval));
    }
    int maxPathSum(TreeNode* root) {
         int ans = INT_MIN;
          solve(root,ans);
          return ans;
    }
};
