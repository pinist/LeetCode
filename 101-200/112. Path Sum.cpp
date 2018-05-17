/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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
    int f=0,s=0;
    void hassum(TreeNode* root, int sum1){
        if(!root||f) return;
        else if(!root->left&&!root->right){
            sum1+=root->val;
            if(sum1>s) return;
            else if(sum1==s){
                f=1;
                return;
            }
                                     
        }
        else{
            hassum(root->left,sum1+root->val);
            hassum(root->right,sum1+root->val);
        }       
        return;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        s=sum;f=0;
        hassum(root,0);
        if(f) return true;
        else return false;
    }
};