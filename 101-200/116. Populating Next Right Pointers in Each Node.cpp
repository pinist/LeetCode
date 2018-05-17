/*
Given a binary tree,Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    
    void connect(TreeLinkNode *root) {
        TreeLinkNode* lstart;lstart=root;
        
        while(lstart!=NULL){
            TreeLinkNode* cur;cur=lstart;
            while(cur!=NULL){
                if(cur->left!=NULL) cur->left->next=cur->right;
                if(cur->right!=NULL&&cur->next!=NULL) cur->right->next=cur->next->left;
                cur=cur->next;
            }
            lstart=lstart->left;
        }
    }
};