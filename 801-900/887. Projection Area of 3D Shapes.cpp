/*
On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.
Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
Now we view the projection of these cubes onto the xy, yz, and zx planes.
A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane. 
Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
Return the total area of all three projections.
 */
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size(),m;
        if(n) m=grid[0].size();
        vector<vector<int> > cc=grid;
        int ans=0;
        for(int i=0;i<n;i++){
            sort(cc[i].begin(),cc[i].end());
            ans+=cc[i][m-1];
            //cout<<ans<<endl;
        }
        for(int j=0;j<m;j++){
            int k=INT_MIN;
            for(int i=0;i<n;i++){
                if(grid[i][j]>k) k=grid[i][j];
                if(grid[i][j]) ans++;
            }
            ans+=k;
            //cout<<k<<' '<<ans<<endl;
        }
        return ans;
    }
};