/*
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    vector<int> ra,rb,tmp;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL){
            tmp.push_back(root->val);
        }
        dfs(root->left);
        dfs(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        ra=tmp; tmp.clear();
        dfs(root2);
        rb=tmp;
        if(ra.size()==rb.size()){
            for(int i=0;i<ra.size();i++){
                if(ra[i]!=rb[i]) return false;
            }
            return true;
        }
        else return false;
    }
};