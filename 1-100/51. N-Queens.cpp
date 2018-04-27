/*
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
*/
class Solution {
public:
    vector<int> C,col,l1,l2;
    vector<vector<string> > ans;
    vector<string> tmp;
    int n,tot;
    string s;
    void dfs(int cur){
        if(cur==n){            
            tmp.assign(n,string(n,'.'));
            for(int i=0;i<n;i++){
                tmp[i][C[i]]='Q';
            }
            ans.push_back(tmp);
        }
        for(int i=0;i<n;i++){
            if(!col[i]&&!l1[cur+i]&&!l2[cur-i+n]){
                C[cur]=i;
                col[i]=l1[cur+i]=l2[cur-i+n]=1;
                dfs(cur+1);
                col[i]=l1[cur+i]=l2[cur-i+n]=0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        C.assign(n,0);
        col.assign(n,0);
        l1.assign(2*n,0);
        l2.assign(2*n,0);
        dfs(0);
        return ans;
    }
};