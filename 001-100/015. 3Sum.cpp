/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        int n=nums.size();
        if(n<3) return res;
        vector<int> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<=n-3;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){            
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[k]);
                    res.push_back(ans);
                    ans.clear();
                    while(j<k&&nums[j]==nums[j+1])  j++;  
                    while(j<k&&nums[k]==nums[k-1])  k--;  
                    j++;k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else j++;
            }
            while((i<n-2)&&nums[i]==nums[i+1]) i++;  
        }
        return res;
    }
};