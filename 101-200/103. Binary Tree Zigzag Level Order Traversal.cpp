/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode*> qu,tmp;
        qu.push(root);
        vector<int> vec;
        int i=1;
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
            if(i) res.push_back(vec);
            else {
                reverse(vec.begin(), vec.end());
                res.push_back(vec);
            }
            i=!i;
        }
        return res;
    }
};