/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
 */
class Solution {
public:
    vector<vector<int> >vis;
    queue<pair<int,int> >qu;
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m; if(n) m=matrix[0].size();
        vector<int>tmp; 
        tmp.assign(m,-1);
        for(int i=0;i<n;i++) vis.push_back(tmp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(!matrix[i][j]) {
                    //cout<<i<<" "<<j<<endl;
                    qu.push(make_pair(i,j));
                    vis[i][j]=0;
                   }//cout<<vis[i][j]<<" "; 
                }
            //cout<<endl;
        }
            
            
        while(!qu.empty()){
            int x=qu.front().first; 
            int y=qu.front().second;qu.pop();
            //cout<<x<<" "<<y<<endl;
            //vis[x][y]=0;
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(0<=nx&&nx<n&&0<=ny&&ny<m&&matrix[nx][ny]&&vis[nx][ny]==-1){
                    vis[nx][ny]=vis[x][y]+1;
                    qu.push(make_pair(nx,ny));
                }
            }
        }
        return vis;
    }                                         
};