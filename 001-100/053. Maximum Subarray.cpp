/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has 
the largest sum and return its sum.
 Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(!n) return 0;
        vector<int> dp;
        
        for(int i=0;i<n;i++) dp.push_back(nums[i]);
        int res=dp[0];
        for(int i=1;i<n;i++) {
            if(dp[i-1]>0) dp[i]=dp[i-1]+nums[i];
            res=max(res,dp[i]);
        }
        return res;
    }
};