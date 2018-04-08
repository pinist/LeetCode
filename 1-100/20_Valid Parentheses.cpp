/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/
class Solution {
public:
    bool isValid(string s) {
        stack <char>st;
        while(!st.empty()) st.pop();
        int si=s.size();
        for(int i=0;i<si;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                else {
                    if(s[i]==')'&&st.top()=='('||s[i]==']'&&st.top()=='['||s[i]=='}'&&st.top()=='{')
                        st.pop();
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};