/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
 */
bool cmp(const string &A, const string &B)
{
    return A.length()<B.length();
}
class Solution {
public:
   
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(!n) return "";
        sort(strs.begin(),strs.end(),cmp);
        int m=strs[n-1].length();
        char cur=strs[0][0];
        string ans;
        int f=1;
        for(int j=0;j<m;j++){
            cur=strs[0][j];
            for(int i=0;i<n;i++){
                if(j>=strs[i].length()) {
                    f=0;
                    break;}
                else{
                    if(strs[i][j]!=cur) {
                        f=0;
                        break;
                    }                    
                }
            }
            if(!f) break;
            ans+=cur;
        }
        return ans;
    }
};