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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans;
        if(!n) return ans;
        int tot=0;
        vector<int> tmp(n,0);
        ans.assign(n,tmp);
        ans[0][0]=1;tot++;
        int x=0,y=0;
        while(tot<n*n){
            while(y+1<n&& !ans[x][y+1]) ans[x][++y]=++tot;
            while(x+1<n&& !ans[x+1][y]) ans[++x][y]=++tot;
            while(y-1>=0&&!ans[x][y-1]) ans[x][--y]=++tot;
            while(x-1>=0&&!ans[x-1][y]) ans[--x][y]=++tot;
        }
        return ans;
    }
};