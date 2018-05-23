/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
 */
class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int res=-1,n=nums.size();
		if(!n) return res;		
		int l=0,r=n-1,m;
		while(r>=l){
			m=l+(r-l)/2;
			if(nums[m]>nums[l]){				
				if(nums[l]<=tar&&nums[m]>=tar){
                    if(nums[m]==tar) return m;
                    else if(nums[l]==tar) return l;
				    else r=m-1;	
				}
                else l=m+1;					
			}
            else if(nums[m]<nums[l]){		
				if(nums[r]>=tar&&nums[m]<=tar){
                    if(nums[m]==tar) return m;
				    else if(nums[r]==tar) return r;
                    else l=m+1;
				}
                else r=m-1;			
			}
            else {
                if(nums[m]==tar) return m;
                else if(nums[r]==tar) return r;
                else r=m-1;
            }
		}
        return -1;
    }
};