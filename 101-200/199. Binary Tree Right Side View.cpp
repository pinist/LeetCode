/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    queue<TreeNode*> qu,tmp;
    vector<int> vec;
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return vec;
        qu.push(root);
        vec.push_back(qu.front()->val);
        while(!qu.empty()){
            while(!qu.empty()){
                if(qu.front()->left!=NULL) tmp.push(qu.front()->left);
                if(qu.front()->right!=NULL) tmp.push(qu.front()->right);
                qu.pop();
            }
            while(!tmp.empty()){
                if(tmp.size()==1) vec.push_back(tmp.front()->val);
                qu.push(tmp.front());
                tmp.pop();
            }
        }
        return vec;
    }
};
