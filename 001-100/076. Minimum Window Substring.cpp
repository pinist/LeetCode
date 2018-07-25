/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

time space:O(128n)
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int tcnt[128]={0},scnt[128]={0};
        int tlen=t.length();
        for(char c:t){
            tcnt[c]++;
        }
        
        int slen=s.length(),cnt=0,ansl=0,ansr=INT_MAX,l=0;
        for(int r=0;r<slen;r++){            
            scnt[s[r]]++;
            int f=1;
            for(int i=0;i<128;i++){
                if(scnt[i]<tcnt[i]) {
                    f=0;break;
                }
            }
            if(f){
                while(scnt[s[l]]>tcnt[s[l]]){
                    scnt[s[l]]--;l++;
                }
                if(r-l<ansr-ansl)
                {   
                    ansl=l;ansr=r;
                    
                } 
            }
            
            //cout<<l<<' '<<r<<' '<<f<<endl;
        }
        return (ansr-ansl)==INT_MAX?"":s.substr(ansl,ansr-ansl+1);
        
    }
};