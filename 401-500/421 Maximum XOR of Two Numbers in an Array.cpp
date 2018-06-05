
class Solution {
public:
    struct TN
    {
        TN* son[2];
        TN()
        {
            son[0]=son[1]=NULL;
        }
    };
    TN *root;
    void insert(int n)
    {
        TN *now=root;
        for(int i=30;i>=0;i--)
        {
            if(now->son[(n>>i)&1]==NULL)
                now->son[(n>>i)&1]=new TN();
            now=now->son[(n>>i)&1];
        }
    }
    int find(int n)
    {
        int ans=0;
        TN *now=root;
        for(int i=30;i>=0;i--)
        {
            int tmp=(n>>i)&1;
            if(now->son[tmp^1]==NULL)
                now=now->son[tmp];
            else
            {
                ans^=(1<<i);
                now=now->son[tmp^1];    
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        root=new TN();
        int ans=0;
        insert(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            ans=max(ans,find(nums[i]));
            insert(nums[i]);
        }
        return ans;
    }
};