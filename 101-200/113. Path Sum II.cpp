/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    stack<int> st,tmp;
    vector<int> cc;
    vector<vector<int>> vec;
    int f=0,s=0,cnt=-1;
    void init(){
        vec.clear();
        while(!st.empty()) {
            st.pop();
        }
        while(!tmp.empty()) {
            tmp.pop();
        }
    }
    void hassum(TreeNode* root, int sum1){
        if(!root) return;
        else if(!root->left&&!root->right){
            sum1+=root->val;
            if(sum1!=s) return;
            else{
                st.push(root->val);
                cnt++;
                while(!st.empty()){
                    tmp.push(st.top());
                    st.pop();
                }
                while(!tmp.empty()){
                    cc.push_back(tmp.top());
                    
                    st.push(tmp.top());
                    tmp.pop();
                }
                
                vec.push_back(cc);
                cc.clear();
                st.pop();
                return;
            }                                     
        }
        else{
            st.push(root->val);
            hassum(root->left,sum1+root->val);
            hassum(root->right,sum1+root->val);
        }
        st.pop();
        
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        init();
        s=sum;cnt=-1;
        hassum(root,0);
        return vec;
    }
};