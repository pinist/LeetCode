/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */
class Solution {
public:
    void dfs(int n,int left,int right,vector<string>& res,string v){
        if(v.length()==n*2){
            res.push_back(v);
            return;
        }
        if(left<n){
            dfs(n,left+1,right,res,v+"(");
        }
        if(left>right){
            dfs(n,left,right+1,res,v+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string v;
        dfs(n,0,0,res,v);
        return res;
    }
};