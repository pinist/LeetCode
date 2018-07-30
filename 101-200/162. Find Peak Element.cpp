/*
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        pair<int,int> tt(INT_MIN,INT_MIN);
        if(n==1) return 0;
        while(i+1<n){
            if(nums[i]<nums[i+1]) {
                i++;continue;
            }
            else{
                if(nums[i]>tt.second){
                    tt.second=nums[i];
                    tt.first=i;
                }
                i++;
            }          
        }
        if(nums[n-1]>tt.second){
            tt.second=nums[i];
            tt.first=i;
        }
        return tt.first;
    }
};
