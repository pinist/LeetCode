/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile,
 adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were 
 broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        int dp[n];
        memset(dp,0,sizeof(dp)); 
        dp[1]=nums[1]; dp[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        int ans=dp[n-1];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0],dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return max(ans,dp[n-2]);
    }
};