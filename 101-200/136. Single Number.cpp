/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
    }
};