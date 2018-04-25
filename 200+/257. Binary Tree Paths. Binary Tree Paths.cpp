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
    vector<string> ans;
    vector<char> res;
    string s;
    void dfs(TreeNode* root,string s){
        if(root==NULL){
            return;
        }
        string tmp=to_string(root->val);
        s.append(tmp);s.append("->");
        if(root->left==NULL&&root->right==NULL)  {
            s.erase(s.end()-2,s.end());
            ans.push_back(s);
        }
        
        dfs(root->left,s);
        dfs(root->right,s);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return ans;
        dfs(root,s);
        return ans;
    }
};