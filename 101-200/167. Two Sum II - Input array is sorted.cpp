/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        vector<int> ans;
        int n=nums.size();int i=0,j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==tar) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(nums[i]+nums[j]>tar) j--;
            else i++;
        }
        return ans;
    }
};