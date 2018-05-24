/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(!n) return 0;
        int l=0,r=n-1;int m=0; int ans=INT_MAX;
        while(l<=r){
            m=l+(r-l)/2;
            ans=min(ans,nums[m]);
            if(nums[m]>nums[r]){               
                l=m+1;
            }
            else if(nums[m]<nums[l]){                
                r=m-1;
            }
            else l++;
        }
        return ans;
    }
};