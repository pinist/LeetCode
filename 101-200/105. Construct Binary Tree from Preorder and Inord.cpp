/*
Given preorder and inorder traversal of a tree, construct the binary tree.
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
    vector<int> pre,in;
    TreeNode* root=NULL;
    TreeNode* build(int l1,int r1,int l2,int r2){
        //cout<<"!"<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        if(l1>r1||l2>r2) 
            return NULL;        
        TreeNode *tmp;
        int cnt=0;
        tmp=new TreeNode(pre[l1]);
        for(int i=l2;i<=r2;i++){
            if(in[i]==tmp->val) {
                cnt=i-l2;
                break;
            }
        }
        //cout<<cnt<<endl;
        tmp->left=build(l1+1,l1+cnt,l2,l2+cnt-1);
        tmp->right=build(l1+cnt+1,r1,l2+cnt+1,r2);
        return tmp;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre.clear();
        in.clear();
        pre=preorder;
        in=inorder;
        root=build(0,in.size()-1,0,in.size()-1);
        return root;
    }
};