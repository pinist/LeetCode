/*
  Idea:
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
  Tag:
    2 pointers. binary search. set.
*/
class Solution {
public:
    vector<int> res;
    vector<int> twoSum(vector<int>& nums, int target) {
        int f=0;
        res.clear();
        for(int i=0;i<nums.size();i++){
            if(f) break;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};