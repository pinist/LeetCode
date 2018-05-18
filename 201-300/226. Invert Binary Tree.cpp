/*
Invert a binary tree.
Example:
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    void invertree(TreeNode* root){
        if(root==NULL) return;
        else{
            if(root->left!=NULL&&root->right!=NULL) {
                TreeNode* tmp;
                tmp=root->left;
                root->left=root->right;
                root->right=tmp;
            }
            else if(root->left!=NULL&&root->right==NULL){
                root->right=root->left;
                root->left=NULL;
            }
            else if(root->left==NULL&&root->right!=NULL){
                root->left=root->right;
                root->right=NULL;
            }
            else{
                return;
            }
        }
        invertree(root->left);
        invertree(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        invertree(root);
        return root;
    }
};