/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    TreeNode* dfs(vector<int> nums,int l,int r){
        if(l>r) return NULL;
        int m=l+(r-l)/2;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=dfs(nums,l,m-1);
        root->right=dfs(nums,m+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return dfs(nums,0,n-1);
    }
};