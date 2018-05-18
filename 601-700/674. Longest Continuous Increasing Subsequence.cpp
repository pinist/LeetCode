/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=0,nans=0,now=INT_MAX;
        for(int i:nums)
        {
            if(i>now)
            {
                now=i; nans++;
            }
            else
            {
                ans=max(ans,nans);
                nans=1;
                now=i;
            }
        }
        ans=max(ans,nans);
        return ans;
    }
};
