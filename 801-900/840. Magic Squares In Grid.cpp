/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 
9 such that each row, column, and both diagonals all have the same sum.
*/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int n=g.size(),m;
        if(n) m=g[0].size();
        else return 0;
        if(n<3||m<3) return 0;
        int pdi=0,npdi=0;
        int ans=0;
        vector<int> cc;
        for(int i=1;i<=9;i++) cc.push_back(i);
        
        vector<int>tmp;
        
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                tmp.clear();
                pdi=g[i][j]+g[i+1][j+1]+g[i+2][j+2];
                npdi=g[i][j+2]+g[i+1][j+1]+g[i+2][j];
                if(npdi!=pdi) continue;
                
                int a1=g[i][j]+g[i+1][j]+g[i+2][j];
                if(a1!=pdi) continue;
                int b1=g[i][j+1]+g[i+1][j+1]+g[i+2][j+1];
                if(b1!=pdi) continue;
                int c1=g[i][j+2]+g[i+1][j+2]+g[i+2][j+2];
                if(c1!=pdi) continue;
                    
                int a=g[i][j]+g[i][j+1]+g[i][j+2];
                if(a!=pdi) continue;
                tmp.push_back(g[i][j]);tmp.push_back(g[i][j+1]);tmp.push_back(g[i][j+2]);
                
                int b=g[i+1][j]+g[i+1][j+1]+g[i+1][j+2];
                if(b!=pdi) continue;
                tmp.push_back(g[i+1][j]);tmp.push_back(g[i+1][j+1]);tmp.push_back(g[i+1][j+2]);
                
                int c=g[i+2][j]+g[i+2][j+1]+g[i+2][j+2];
                if(c!=pdi) continue;
                tmp.push_back(g[i+2][j]);tmp.push_back(g[i+2][j+1]);tmp.push_back(g[i+2][j+2]);
                
                sort(tmp.begin(),tmp.end());
                //for(auto v:tmp) cout<<v<<" ";
                if(tmp==cc) ans++;                              
            }
        }
        return ans;
    }
};