class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int n=S.size();
        vector<int> ans;
        vector<vector<int> >res;
        int i=0;
        while(i<n){
            if(S[i]!=S[i+1]||i==n-1){
                i++;continue;
            }
            else{
                int mark=i;
                ans.push_back(i);
                while(S[i]==S[mark]&&i<n){
                    i++;
                }
                //cout<<i-mark;
                if((i-mark)>=3){
                    ans.push_back(i-1);
                    res.push_back(ans);
                }
                ans.clear();
            }
        }
        return res;
    }
};