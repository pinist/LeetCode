/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
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
    int cnt=0;
    bool issym(TreeNode*p, TreeNode*q){
        if(!p&&!q) return true;
        else if(p&&!q) return false;
        else if(!p&&q) return false;
        else {
            if(p->val!=q->val) return false;
            else  return(issym(p->left,q->right)&&issym(q->left,p->right));
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        cnt++;
        if(!root) return true;
        else {
            return issym(root->left,root->right);
        }
    }
};