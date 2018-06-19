/*
Let's call an array A a mountain if the following properties hold:
A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] 
> A[i+1] > ... > A[A.length - 1].
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int ans=0,n=A.size();
        if(!n) return ans;
        int f=0;
        for(int i=0;i<n;i++){
            if(A[i]>ans) {
                f=i;
                ans=A[i];
            }
        }
        return f;
    }
};