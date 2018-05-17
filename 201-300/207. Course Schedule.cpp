/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 */
class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;

    bool hasloop(int u){
        if(vis[u]==1) return 1;
        if(vis[u]==2) return 0;
        vis[u]=1;
        for(auto v: g[u]) if(hasloop(v)) return 1;
        vis[u]=2;
        return 0;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        for(int i=0;i<numCourses;i++) {
            g.emplace_back();
            vis.push_back(0);
        }
        for(int i=0;i<prerequisites.size();i++) g[prerequisites[i].second].push_back(prerequisites[i].first);
        bool f=0;
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]&&hasloop(i)) return 0;
            
        }
        return 1;
    }
};