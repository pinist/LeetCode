/*
Given a collection of distinct integers, return all possible permutations.
 */
class Solution {
public:
    vector<vector<int> >res;
    vector<int> vis; vector<int> nu,tmp;
    int n;
    void dfs(int cur){               
        if(cur==n){
            res.push_back(tmp);
            return;
        }
        //for(int i=0;i<=cur;i++) cout<<tmp[i]<<" ";
        for(int i=0;i<n;i++){
            if(!vis[i])
		    {
			    vis[i]=1;
                if(tmp.size()==cur) tmp.emplace_back();
			    tmp[cur]=nu[i];
			    dfs(cur+1);
			    vis[i]=0;
		    }
        }
    }    
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        if(!n) return res;
        this->nu=nums;
        vis.assign(n,0);
        tmp.assign(n,0);
        
        dfs(0);
        return res;
    }
};