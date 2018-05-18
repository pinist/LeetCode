/*Given an unsorted array of integers, find the length of longest increasing subsequence.
Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 8?
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int> dp,nlis;
        dp.assign(n+1,0);nlis.assign(n+1,0);
        for(int i=0; i<n;i++){
            int k=lower_bound(nlis.begin(),nlis.begin()+ans,nums[i])-nlis.begin();
            if(k==ans) ans++;
            nlis[k]=nums[i];
            dp[i]=ans+1;
        }
        return ans;
    }
};