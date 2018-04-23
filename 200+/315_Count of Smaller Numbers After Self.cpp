
class Solution {
public:
    vector<int> sums;
    int lowbit(int x)
    {
        return x&(-x);
    }
    
    int getsum(int n){
        int ans=0;
        while(n>0){
            ans+=sums[n];
            n-=lowbit(n);
        }
        return ans;
    }
    
    void update(int n,int val){
        while(n<sums.size()){
            sums[n]+=val;
            n+=lowbit(n);
        }
    }
    
    vector<int> a2;
    vector<int> d2;
    vector<int> cnt;
    int getid(int n){
        return lower_bound(d2.begin(),d2.end(),n)-d2.begin();
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        sums.clear();
        d2.clear();
        cnt.clear();
        a2.clear();
        d2.assign(nums.begin(),nums.end());
        int v=d2.size();
        cnt.assign(v+1,0);
        sums.assign(v+1,0);
        sort(d2.begin(),d2.end());
        for(int i=v-1;i>=0;i--){
            cnt[getid(nums[i])+1]++;
            if(cnt[getid(nums[i])+1]==1)
                update(getid(nums[i])+1,cnt[getid(nums[i])+1]);
            else
                update(getid(nums[i])+1,1);
            a2.push_back(getsum(getid(nums[i])));
        }
        vector<int> res;
        for(int i=v-1;i>=0;i--)
            res.push_back(a2[i]);
        return res;
    }
};