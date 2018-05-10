/*
Given a binary tree, determine if it is a valid binary search tree (BST).
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef long long LL;
    int f;
    pair<LL,LL> dfs(TreeNode *root)
    {
        if(root==NULL) return make_pair((LL)INT_MAX+1,(LL)INT_MIN-1);
        pair<LL,LL> l=dfs(root->left),r=dfs(root->right);
        if(!(l.second < root->val && root->val < r.first)) f=0;
        return make_pair(min(l.first,(LL)root->val),max((LL)root->val,r.second));
    }
    bool isValidBST(TreeNode* root) {
        f=1;
        dfs(root);
        return f;
    }
};
