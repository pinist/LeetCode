class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,now=0,p=0;
        set<char> se;
        for(char c:s)
        {
            while(se.count(c))
            {
                se.erase(s[p++]);
                now--;
            }
            se.insert(c); now++;
            ans=max(ans,now);
        }
        return ans;
    }
};