/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> ma;
        int n=nums.size();
        if(!n) return nums.size();
        vector<int>::iterator iter=nums.begin();
        while(iter!=nums.end()){
            if(ma.find(*iter)==ma.end()) {
                ma[*iter]=1;
                iter++;
            }
            else if(ma[*iter]==2){
                iter=nums.erase(iter);
            }
            else{
                ma[*iter]++;
                iter++;
            }           
        }
        return nums.size();
    }
};