/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 */
class Solution {
public:
    unordered_map<char,string> mp;
        
    vector<string>ans;
    int n;
    string tmp;
    void dfs(string s,int dep){
        if(dep==n) {
            ans.push_back(tmp);
            return;
        }
        string re=mp[s[dep]];
        for(char c:re){
            tmp[dep]=c;
            dfs(s,dep+1);
        }
    }
    vector<string> letterCombinations(string dig) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        n=dig.length();
        if(!n) return ans;
        tmp.assign(n,0);
        dfs(dig,0);
        return ans;
    }
};