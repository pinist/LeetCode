/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        if (g.empty())
            return 0;
        if (g[0][0] == 1)
            return 0;
        int n=g.size(),m=g[0].size();
        
        vector<vector<int> > dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(g[0][i]==0) dp[0][i]=1;
            else break;
        }
        
        for(int i=0;i<n;i++) {
            if(!g[i][0]) dp[i][0]=1;
            else break;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(g[i][j]) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];                    
            }
        }
        return dp[n-1][m-1];
    }
};