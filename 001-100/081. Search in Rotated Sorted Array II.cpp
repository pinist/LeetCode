/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.
 */
class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int n=nums.size();
		if(!n) return false;		
		int l=0,r=n-1,m;
		while(r>=l){
			m=l+(r-l)/2;
            if(nums[m]==tar) return true;
			if(nums[m]>nums[l]){				
				if(nums[l]<=tar&&nums[m]>=tar){
                    if(nums[m]==tar||nums[l]==tar) return true;           
				    else r=m-1;	
				}
                else l=m+1;					
			}
            else if(nums[m]<nums[l]){		
				if(nums[r]>=tar&&nums[m]<=tar){
                    if(nums[m]==tar||nums[r]==tar) return true;
                    else l=m+1;
				}
                else r=m-1;			
			}
            else {
                l++;
            }
		}
        return false;
    }
};