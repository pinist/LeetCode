/*
Given a binary tree, determine if it is height-balanced.
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
    int f=1;
    int istree(TreeNode*root ){
        if(root==NULL||!f) return 0;
        int a=istree(root->left)-istree(root->right);
        if(abs(a)>1) {
            f=0;
        }
        return max(istree(root->left),istree(root->right))+1;
    } 
    bool isBalanced(TreeNode* root) {
        f=1;
        istree(root);
        if(f) return true;
        else return false;
    }
};