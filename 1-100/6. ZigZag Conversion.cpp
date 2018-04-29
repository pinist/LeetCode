/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
 */
class Solution {
public:
    vector<vector<char> >ans;
    
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        ans.assign(numRows+1,vector<char>());
        int p=0,f=0,i=0;
        while(i<s.size()){
            while(p<numRows&&!f){
                ans[++p].push_back(s[i]);
                //cout<<"p="<<p<<' '<<s[i]<<' '<<"i="<<i<<endl;
                i++;if(i==s.size()) break;
                if(p==numRows) f=1;
            }
            while(p>0&&f){
                ans[--p].push_back(s[i]);
                //cout<<"p="<<p<<' '<<s[i]<<' '<<"i="<<i<<endl;
                i++;if(i==s.size()) break;
                if(p==1) f=0;
            }
        }
        
        string res;
        for(int i=0;i<=numRows;i++){
            for(auto v:ans[i]) res.push_back(v);
        }
        return res;
    }
};