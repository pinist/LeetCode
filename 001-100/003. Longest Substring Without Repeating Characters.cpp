/*Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    map<char, int> ma;
    vector<int> vec;
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int cnt=s.size();
        int pre=0, now=0;
        int remax=0;
        for(int i=0;i<cnt;i++){
            if(ma.find(s[i])==ma.end()) {
                ma[s[i]]=i;
                remax=max(remax,i-pre+1);                
            }
            else{
                pre=(ma.find(s[i])->second)+1;
                remax=max(remax,i-pre+1);
                ma.clear();
                ma[s[pre]]=pre;
                i=pre;
            }
            //cout<<remax<<endl;
        }
        return remax;
    }
};