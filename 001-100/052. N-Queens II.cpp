/*
Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 */
class Solution {
public:
    int ans, n;
    vector<int> vis,l1,l2;
    void dfs(int cur){
       if(cur==n) {
           
           ans++;//cout<<ans;
           return;
       } 
       for(int i=0;i<n;i++){
           if(!vis[i]&&!l1[cur+i]&&!l2[cur-i+n]){
               vis[i]=l1[cur+i]=l2[cur-i+n]=1;
               dfs(cur+1);
               vis[i]=l1[cur+i]=l2[cur-i+n]=0;
           }
       }
        return;
        
    }
    
    int totalNQueens(int n) {
        ans=0;this->n=n;
        vis.assign(n,0);
        l1.assign(2*n,0);
        l2.assign(2*n,0);
        dfs(0);
        return ans;
    }
};