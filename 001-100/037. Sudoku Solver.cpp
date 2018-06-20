/*
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
 */
class Solution {
public:
    int n=9;
    bool f=false;
    void dfs(int i,int j,vector<vector<char>>& b){
        if(j==n) dfs(i+1,0,b);        
        else if(i==n){
            f=true;
            return;
        }        
        else if (b[i][j]!='.') dfs(i,j+1,b);          
        else{
            for(int k=1;k<=9;k++){
                b[i][j]=char('0'+k);
                if(is_val(i,j,b)) dfs(i,j+1,b);
                if(f==true) return;   
                b[i][j]='.';  
            }
        }
        return;
    }
    
    bool is_val(int i,int j,vector<vector<char>>& b){
        for(int index=0;index<n;++index){  
            if (index!=j&&b[i][index]==b[i][j]) return false;                
        }  
  
        for(int index=0;index<n;++index){  
            if (index!=i&&b[index][j]==b[i][j]) return false;                
        }  
  
        int index_i=i/3;  
        int index_j=j/3;  
          
        for(int x=index_i*3;x<index_i*3+3;++x){  
            for(int y=index_j*3;y<index_j*3 +3;++y){  
                if((x!=i||y!=j)&&b[x][y]==b[i][j]) return false;                    
            }  
        }  
        return true;  
    }
    
    void solveSudoku(vector<vector<char>>& b) {
        f=false;       
        dfs(0,0,b);
        return;
    }
};