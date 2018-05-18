/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 */
class Solution {
public:
    vector<vector<int> >g;
    vector<pair<int, int> >pre;
    vector<int> vis,res;
    int num;
    bool dfs(int u){      //return true if has loop
        if(vis[u]==1) return 1;
        if(vis[u]==2) return 0;
        vis[u]=1;
        for(auto v:g[u]){
            if(dfs(v)) return 1;
        }
        vis[u]=2;
        res.push_back(u);
        return 0;
    }
    
    bool topo_sort()   // if cannot do topo_sort return false
    {	
	    for(int i=0;i<num;i++)
		    if(!vis[i]&&dfs(i)) return 0;
	    return 1;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        num=numCourses;
        pre=prerequisites;
        for(int i=0;i<num;i++){
            g.emplace_back();
            vis.push_back(0);
        }
        for(auto i:pre){
            g[i.second].push_back(i.first);
        }
        
        if(!topo_sort()) 
            res.clear();
        reverse(res.begin(),res.end());
        return res;
    }
};
