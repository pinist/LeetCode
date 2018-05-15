/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int > dp; int n=grid[0].size(),m=grid.size();
        dp.push_back(grid[0][0]);
        for(int i=1;i<n;i++){
           dp.push_back(grid[0][i]+dp[i-1]); 
        }
        //for(auto i:dp) cout<<i<<" ";
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0) dp[j]=dp[j]+grid[i][j];
                else dp[j]=min(dp[j]+grid[i][j],dp[j-1]+grid[i][j]);
            }
        }
        return dp[n-1];
    }
};