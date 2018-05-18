/*
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 */
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
    
    vector<int> a2,d2,cnt;

    int getid(int n){
        return lower_bound(d2.begin(),d2.end(),n)-d2.begin()+1;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        d2=nums;
        sort(d2.begin(),d2.end());
        d2.erase(unique(d2.begin(),d2.end()),d2.end());
        int v=d2.size();
        cnt.assign(v+1,0);
        sums.assign(v+1,0);
        a2.assign(nums.size(),0);
        int tmp=0;
        for(int i=v-1;i>0;i--){
            tmp=getid(nums[i]);
            update(tmp,1);
            a2[i]=getsum(tmp-1);
        }        
        return a2;
    }
};