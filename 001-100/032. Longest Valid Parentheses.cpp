/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) 
parentheses substring.
Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
 */
class Solution {
public:
    int longestValidParentheses(string s){
        stack<int> sta;
        int ret=0,start=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                sta.push(i);
            else{
                if(sta.empty()){
                    start=i; 
                }
                else{
                    sta.pop();
                    if(!sta.empty())
                        ret=max(ret,i-sta.top());
                    else
                        ret=max(ret,i-start); 
                }                
            }
        }
        return ret;
    }
};