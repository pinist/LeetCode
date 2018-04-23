/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    vector<int> in, post;
    TreeNode* root;
    TreeNode* build(int l1,int r1,int l2,int r2){
       // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        if(l1>r1||l2>r2) return NULL;
        TreeNode* tmp;
        tmp=new TreeNode(post[r2]);
        int cnt=0;
        for(int i=l1;i<=r1;i++){
            if(in[i]==tmp->val){
                cnt=i-l1;
                //cout<<"!"<<cnt<<endl;
                break;
            }
        }

        tmp->left=build(l1,l1+cnt-1,l2,l2+cnt-1);
        tmp->right=build(l1+cnt+1,r1,l2+cnt,r2-1);
        return tmp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in.clear();post.clear();
        this->in=inorder;
        this->post=postorder;
        return build(0,in.size()-1,0,post.size()-1);
    }
}; 