/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(!n) return false;
        int m=matrix[0].size(),i=n-1,j=0;        
        while(i>=0&&j<m){
            if(target>matrix[i][j]) j++;
            else if(target<matrix[i][j]) i--;
            else return true;
        }
        return false;
    }
};
