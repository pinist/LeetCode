
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int res=0;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                int count=0;
                for(int k=max(i,0);k<min(n+i,n);k++){
                    for(int l=max(j,0);l<min(n+j,n);l++){
                        if(A[k-i][l-j]&&B[k][l]){
                            count++;
                        }
                    }
                }
                res=max(res,count);
            }
        }
        return res;
    }
};