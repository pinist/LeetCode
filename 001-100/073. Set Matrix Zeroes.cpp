/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col;
        set<int> r;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    col.insert(i);
                    r.insert(j);
                }
            }
        }
        
        for(auto j:col)
            for(int i=0;i<matrix[0].size();i++)
                matrix[j][i]=0;
        for(auto j:r)
            for(int i=0;i<matrix.size();i++)
                matrix[i][j]=0;
        
    }
};