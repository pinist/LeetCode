/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
    vector<vector<int>> res;
    void pushlevel(TreeNode* root,int depth){
        if(root==NULL) return;
        if(res.size()==depth) res.emplace_back();
        res[depth].push_back(root->val);
        pushlevel(root->left,depth+1);
        pushlevel(root->right,depth+1);
        return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return res;
        pushlevel(root,0);
        reverse(res.begin(), res.end());
        return res;
    }
};