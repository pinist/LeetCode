/*
Given two strings s and t , write a function to determine if t is an anagram of s.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> tt;
        tt.assign(26,0);
        for(auto c:s) tt[c-'a']++;
        for(auto c:t) tt[c-'a']--;
        for(auto i:tt) if(i!=0) return false;
        return true;
    }
};