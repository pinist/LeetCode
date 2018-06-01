/*
Given an array nums of n integers and an integer target, find three integers in nums such thatthe sum is closest
to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int n=nums.size();
        int res=0;
        if(n<3) return res;
        sort(nums.begin(),nums.end());
        int clo_sum=nums[0]+nums[1]+nums[2];
        int dif=abs(clo_sum-tar);
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;            
            while(l<r){
                int sum=nums[l]+nums[r]+nums[i];
                int a_dis=abs(sum-tar);
                if(a_dis<dif){
                    clo_sum=sum;
                    dif=a_dis;
                }
                if(sum>=tar) r--;
                else l++;
            }
        }
        return clo_sum;
    }
};