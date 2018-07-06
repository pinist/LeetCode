/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int tmp=nums[0];
        int n=nums.size();
        if(!n) return true;
        for(int i=0;i<n;i++){
            if(tmp>=n-1) return true;
            if(i>tmp) return false;
            else{
                tmp=max(tmp,i+nums[i]);
            }
        }
    }
};