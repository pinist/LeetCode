class Solution {
public:
    int maxd=0,n;
    vector<int> d,idx;
    vector<vector<int> >g;
    queue<int> qu;
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    
    int bfs(){
        for(int i=0;i<n*n;i++)
            if(!idx[i]) {
                qu.push(i);
                d[i]=1;
            }
        while(!qu.empty()){            
            int u=qu.front();qu.pop();maxd=d[u];
            for(auto v:g[u]){
                if(!(--idx[v])){
                    d[v]=d[u]+1;
                    qu.push(v);
                }
                
            }
        }
        return maxd;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        g.assign(n,vector<int>());
        d.assign(n*n,0);
        idx.assign(n*n,0);
        if(!n) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int m=0;m<4;m++){
                    int x=i+dx[m], y=j+dy[m];
                    if(0<=x&&x<n&&0<=y&&y<n&&matrix[i][j]<matrix[x][y]){
                        g[i*n+j].push_back(x*n+y);
                        idx[x*n+y]++;
                    }   
                }                   
            }
        }
        return bfs();
    }
};