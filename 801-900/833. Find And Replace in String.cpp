class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int,pair<int, string>,greater<int> >m;
        for(int i=0;i<indexes.size();i++) 
        if(S.substr(indexes[i], sources[i].size())==sources[i]) 
            m[indexes[i]]={sources[i].size(),targets[i]};
        for (auto r:m) 
            S.replace(r.first,r.second.first,r.second.second);
        return S;
    }
};