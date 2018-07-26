/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        for(int i=0;i<=rowIndex;++i)
        {
            vector<int> iV(i+1,1);
            if (i>=2)
            {
                for(int j=1;j<i;++j)
                    iV[j]=v[i-1][j-1]+v[i-1][j];
            }
            v.push_back(iV);
        }
        return v[rowIndex];
    }
};