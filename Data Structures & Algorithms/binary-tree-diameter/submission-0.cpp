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
    int findDia(TreeNode* root, int&ans) {
        if(!root) return 0;
        int ld = findDia(root->left,ans);
        int rd = findDia(root->right,ans);
        ans = max(ans,ld+rd);
        return 1+max(ld,rd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int ans =1;
        findDia(root,ans);
        return ans;
    }
};