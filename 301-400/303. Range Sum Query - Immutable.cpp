/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
 */
class NumArray {
public:
    vector<int> sum;
    
    NumArray(vector<int> nums) {
        sum.push_back(0);
        for(int i=0;i<nums.size();i++){
            sum.push_back(nums[i]+sum[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};