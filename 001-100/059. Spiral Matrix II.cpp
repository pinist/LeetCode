/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example, 
Given n = 3,
You should return the following matrix: 
[ [ 1, 2, 3 ], 
[ 8, 9, 4 ], 
[ 7, 6, 5 ] ]
*/
class Solution {
public:
    vector<int> spiralOrder(int n) {
        vector<int> ans;
        if(!n) return ans;
        int x=0,y=0;
        vector<vector<int> >vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int tot=2;
        while(tot<(n*n)){
            while(y+1<n&&!vis[x][y+1])  vis[x][++y]=tot++;
            while(x+1<m&&!vis[x+1][y])  vis[++x][y]=tot++;
            while(y-1>=0&&!vis[x][y-1]) vis[x][--y]=tot++;
            while(x-1>=0&&!vis[x-1][y]) vis[--x][y]=tot++;
        }
        return vis;
    }
};