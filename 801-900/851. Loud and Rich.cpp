/*
In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.
For convenience, we'll call the person with label x, simply "person x".
We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be a subset of valid observations.
Also, we'll say quiet[x] = q if person x has quietness q.
Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), among all people who definitely have equal to or more money than person x.
 */
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int> > g(n,vector<int>() );
        vector<int> ans,ind(n,0), minq;
        for(int i=0;i<richer.size();i++){
            g[richer[i][0]].push_back(richer[i][1]);
            ind[richer[i][1]]++;
        }
        for(int i=0;i<n;i++){
            minq.push_back(quiet[i]);
            ans.push_back(i);
        }
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(!ind[i]) qu.push(i);
        }
        while(!qu.empty()){
            int u=qu.front();qu.pop();            
            for(auto i:g[u]){
                if(minq[u]<minq[i]){
                   minq[i]=minq[u];
                   ans[i]=ans[u];
                }
                if(!--ind[i]) qu.push(i);
            }
        }
        return ans;
    }
};