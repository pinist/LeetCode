/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
 */
class Solution {
public:
    queue<pair<int,int> >qu;
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        int m=board.size(); int n=board[0].size();
        vector<vector<char> > ans(m,vector<char>(n,'X'));
        vector<vector<bool> > vis(m,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') qu.emplace(0,i);
            if(board[m-1][i]=='O') qu.emplace(m-1,i);
        }
        for(int i=1;i<m-1;i++) {
            if(board[i][0]=='O') qu.emplace(i,0);
            if(board[i][n-1]=='O') qu.emplace(i,n-1);
        }
        pair<int,int> p;
       
        while(!qu.empty()){
            p=qu.front();qu.pop();
            int x=p.first; int y=p.second;
            if(vis[x][y]) continue;
            vis[x][y]=1;
            ans[x][y]='O';
            for(int i=0;i<4;i++){
                int nx=x+dx[i];int ny=y+dy[i];
                if(0<=nx&&nx<m&&0<=ny&&ny<n&&board[nx][ny]=='O'&&!vis[nx][ny]) 
                    qu.emplace(nx,ny);
            }
        }
        board=ans;
        return;
    }
};