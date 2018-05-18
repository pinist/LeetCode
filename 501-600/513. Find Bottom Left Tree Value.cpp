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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        qu.push(root);
        int ans=root->val;
        while(!qu.empty()){
            while(!qu.empty()){
                TreeNode* a=qu.front();qu.pop();
                if(a->left!=NULL) tmp.push(a->left);
                if(a->right!=NULL) tmp.push(a->right);
            }
            while(!tmp.empty()){
                vec.push_back(tmp.front()->val);
                qu.push(tmp.front());
                tmp.pop();
            }
            ans=(vec.size()==0?ans:vec[0]);vec.clear();
      
        }
        return ans;
    }
};