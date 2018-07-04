/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        string ans;
        vector<int> mp(2*len+3,0);
        string ms;        
        ms+='$';ms+='#';
        for(int i=0;i<len;i++){
            ms+=s[i];
            ms+="#";
        }
        ms+='0';
        int mslen=ms.length();
        
        int p=0,o=0,res=-1;
        for(int i=1;i<mslen;i++){
            int k=p>i?min(mp[2*o-i],p-i):1;
            while(ms[i+k]==ms[i-k]) k++;
            if(i+k>p){
                p=i+k;
                o=i;
            }
            mp[i]=k;
            res=max(res,mp[i]);
        }
        int cen=0,rad=0;
        for(int i=1;i<mp.size();i++){
            if(mp[i]>rad){
                rad=max(rad,mp[i]);
                cen=i;
            }     
        }
        //cout<<cen<<" "<<rad;
        for(int i=cen-rad+2;i<cen+rad;i+=2)
            ans+=ms[i];
        return ans;
        
    }
};