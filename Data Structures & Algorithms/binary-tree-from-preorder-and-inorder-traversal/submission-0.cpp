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
    TreeNode* build(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int>&mp ){
        if(ps>pe || is>ie) {
            return NULL;
        }
        TreeNode* curr = new TreeNode(preorder[ps]);
        int idx = mp[curr->val];
        curr->left = build(preorder,ps+1,ps+(idx-is),inorder,is,idx-1,mp);
        curr->right = build(preorder,ps+(idx-is)+1,pe,inorder,idx+1,ie,mp);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]]=i;
        }
        return build(preorder,0,n-1,inorder,0,n-1,mp);
    }
};
