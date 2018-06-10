/*
We have a string S of lowercase letters, and an integer array shifts.
Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a'). 
For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.
Return the final string after all such shifts to S are applied.
 */
class Solution {
public:
    string shiftingLetters(string S, vector<int>& sf){
        string ans;
        int n=sf.size();
        if(!n) return S;
        vector<long long> sum(n,0);
        sum[n-1]=sf[n-1];
        for(int i=n-2;i>=0;i--) sum[i]=sum[i+1]+sf[i];
        int m=S.length();
        int len=min(m,n);
        for(int i=0;i<len;i++){
            char c=((S[i]-'a')+sum[i])%26+'a';
            ans+=c;
        }
        return ans;
    }
};