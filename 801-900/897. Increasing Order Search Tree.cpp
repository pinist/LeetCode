/*
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1
 right child.
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
    vector<int> tmp;
    void dfs(TreeNode* root){
        
        if(root==NULL) return;
        dfs(root->left);
        tmp.push_back(root->val);
        dfs(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* ans=new TreeNode(tmp[0]);
        TreeNode* p=ans;
        for(int i=1;i<tmp.size();i++){
            ans->right=new TreeNode(tmp[i]);
            ans=ans->right;
        }
        return p;
    }
};