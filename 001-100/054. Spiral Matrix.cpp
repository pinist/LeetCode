/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m=mat.size(),n;
        if(m) n=mat[0].size();
        else return ans;
        if(!n) return ans;
        int x=0,y=0;
        vector<int> cc;
        cc.assign(n,0);
        vector<vector<int> >vis;
        vis.assign(m,cc); 
        
        ans.push_back(mat[0][0]);vis[0][0]=1;
        while(ans.size()<(m*n)){
            while(y+1<n&& !vis[x][y+1]) {ans.push_back(mat[x][++y]);vis[x][y]=1;}
            while(x+1<m&& !vis[x+1][y]) {ans.push_back(mat[++x][y]);vis[x][y]=1;}
            while(y-1>=0&& !vis[x][y-1]) {ans.push_back(mat[x][--y]);vis[x][y]=1;}
            while(x-1>=0&& !vis[x-1][y]) {ans.push_back(mat[--x][y]);vis[x][y]=1;}
        }
        return ans;
    }
};