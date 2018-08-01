/*
Youu are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(!n) return 0;
        
        for(int i=2;i<n;i++){
            nums[i]+=max(nums[i-2],nums[i-3]);
        }
        return max(nums[n-1],nums[n-2]);
    }
};