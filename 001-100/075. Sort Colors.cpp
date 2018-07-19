/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> ma;
        int n=nums.size();
        if(!n) return;
        for(int i=0;i<n;i++){
            if(ma.find(nums[i])==ma.end()) ma[nums[i]]=1;
            else ma[nums[i]]++;
        }
        int k=0;
        map<int,int>::iterator iter;
        for(iter=ma.begin();iter!=ma.end();iter++){
            int i=iter->second;
            while(i--){
                nums[k]=iter->first;
                k++;
            }
        }
    }
    
};