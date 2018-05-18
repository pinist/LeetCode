/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
 */
class NumArray {
public:
    vector<int> sums;
    vector<int> nums;
    NumArray(vector<int> nums) {
        this->nums=nums; 
        sums.resize(nums.size()+1);
        for(int i=0;i<nums.size();i++)
            change(i+1,nums[i]);
    }
    int lowbit(int x){
        return x&(-x);
    }
    void change(int i, int val) {
        while(i<sums.size()){
            sums[i]+=val;
            i+=lowbit(i);
        }
    }
    int sum(int n){
        int ans=0;
        while(n>0){
            ans+=sums[n];
            n-=lowbit(n);
        }
        return ans;
    }
    void update(int i, int val) {
        int delta = val-nums[i];
        nums[i] = val;
        change(i+1,delta);
    }
    int sumRange(int i, int j) {
        return sum(j+1)-sum(i);
    }
};

