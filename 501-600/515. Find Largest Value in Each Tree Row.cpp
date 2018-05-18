/*
You need to find the largest value in each row of a binary tree.
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
    vector<int> ans;
    queue<TreeNode*>qu,tmp;
    
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return ans;
        qu.push(root);ans.push_back(root->val);
        while(!qu.empty()){
            int res=INT_MIN;
            while(!qu.empty()){
                if(qu.front()->left!=NULL) tmp.push(qu.front()->left);
                if(qu.front()->right!=NULL) tmp.push(qu.front()->right);
                qu.pop();
            }
            while(!tmp.empty()){
                res=max(res,tmp.front()->val);
                qu.push(tmp.front());
                tmp.pop();
            }
            ans.push_back(res);
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};