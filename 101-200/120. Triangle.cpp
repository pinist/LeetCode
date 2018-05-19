/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        if(!n) return 0;
        vector<int> dp;
        for(int i=0;i<n;i++) dp.push_back(tri[n-1][i]);
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++)
                dp[j]=min(dp[j],dp[j+1])+tri[i][j];
        }
        return dp[0];
    }
};