/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 题点：之前做这道题debug的时候一直没有发现错误，后来才知道是convert 的返回值不对，导致树并没有链接起来。
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
        tmp.push_back(root->val);
        dfs(root->left);dfs(root->right);
        return;
    }
    
    TreeNode* convert(TreeNode *root,int dep){
        if(dep==tmp.size()) return NULL;  
        if(dep) root=new TreeNode(tmp[dep]);
        root->left=NULL;
        root->right=convert(root->right,dep+1);
        return root;
    }
    
    queue<TreeNode*> qu;
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        dfs(root); //root->left=NULL;
        convert(root, 0);
        return ;
    }
};