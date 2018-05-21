/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.
 */
class Solution {
public:
    int numDecodings(string s){
        int n=s.length();
        if(!n||s[0]=='0') return 0;        
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=1;i<n;++i){
            int t=(int)atoi(s.substr(i-1,2).c_str());
            //cout<<t<<endl;
            if(s[i]=='0') dp[i]=0;            
            if(t>=1&&t<=26) dp[i+1]=dp[i]+dp[i-1];
            else dp[i+1]=dp[i];
        }
        return dp[n];
    }
};