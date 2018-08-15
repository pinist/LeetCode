/*
Given a list of non negative integers, arrange them such that they form the largest number.
Example 1:
Input: [10,2]
Output: "210"
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> res;
        for(int i=0;i<n;i++) res.push_back(to_string(nums[i]));
        
        sort(res.begin(),res.end(),[](string &a,string &b){return a+b>b+a;});
        string ans;
        for(int i=0;i<res.size();i++){
            ans+=res[i];
        }
        while(ans[0]=='0'&&ans.length()>1) ans.erase(0,1);
        return ans;
    }
};