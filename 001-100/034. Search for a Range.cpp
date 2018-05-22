/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
*/
class Solution {
public:
    int lowbs(int n, int target, vector<int> nums ){
        int start=0,end=n-1,mid=0,ans=n;
        while(start<=end){
            
            mid=start+(end-start)/2;
            if(target<=nums[mid]){
                ans=min(ans,mid);
                end=mid-1;
            }
            else start=mid+1;
        }
        return start;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int csize=nums.size();
        vector<int> res;
        res.assign(2,-1);
        if(!csize) return res;
        sort(nums.begin(),nums.end());
        int a=lowbs(csize,target,nums),b=lowbs(csize,target+1,nums)-1;
        if(a<csize&&nums[a]==target){
            res.clear();
            res.push_back(a);
            res.push_back(b);
        }
        return res;
    }
};