/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
  3
   / \
  9  20
    /  \
   15   7
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

/*
Idea: using temporary queue to solve problem
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode*> qu,tmp;
        qu.push(root);
        vector<int> vec;
        while(!qu.empty()){
            vec.clear();
            while(!qu.empty()){
                if(qu.front()->left!=NULL) tmp.push(qu.front()->left);
                if(qu.front()->right!=NULL) tmp.push(qu.front()->right);
                vec.push_back(qu.front()->val);
                qu.pop();
            }
            while(!tmp.empty()){
                qu.push(tmp.front());
                tmp.pop();
            }
            res.push_back(vec);
        }
        return res;
    }
};