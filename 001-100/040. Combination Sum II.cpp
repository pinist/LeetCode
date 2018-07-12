/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.
 */
class Solution {
public:    
    vector<int> tmp;
    vector<vector<int>> res; 
    void solve(vector<int>& candidates,int target,int index){       
        if(target==0) res.push_back(tmp);
        else if(target>0){            
            for(int i=index;i<candidates.size()&&target>=candidates[i];i++){              
                if(candidates[i]==candidates[i-1]) continue;
                tmp.push_back(candidates[i]);  
                vector<int> local=candidates;
                local.erase(local.begin()+i);
                solve(local, target-candidates[i], i);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){        
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);
        return res;
    }    
    
};