/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
 */
class Solution {
public:
    int cnt=0,m,n;
    vector<vector<char>> grid;
    vector<vector<int>> idx;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    void dfs(int r, int c, int id){
        int v=grid.size();
        if(r>=m||c>=n||c<0||r<0) return;
        if(idx[r][c]>0||grid[r][c]!='1') return;
        idx[r][c]=id;
        for(int i=0;i<4;i++) {
            int nx=r+dx[i];int ny=c+dy[i];
            dfs(nx,ny,id);
        }     
    }
    
    int numIslands(vector<vector<char>>& grid) {
        this->grid=grid;
        cnt=0;
        m=grid.size();
        if(!m) return 0;
        n=grid[0].size();        
        vector<int> vec;
        vec.assign(n,0);
        for(int i=0;i<m;i++) idx.push_back(vec);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(idx[i][j]==0&&grid[i][j]=='1')
                    dfs(i,j,++cnt);
            }
                            
        }
        return cnt;
    }
};