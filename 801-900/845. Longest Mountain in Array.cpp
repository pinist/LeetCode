/*
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)
Given an array A of integers, return the length of the longest mountain. 
Return 0 if there is no mountain.
 */
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        int i=0,ans=0,mark=0;
        vector< pair<int,int> > cc;
        while(i+1<n){
            if(A[i]<A[i+1]) {
                i++;continue;
            }
            else{                
                ans=max(ans,i-mark+1);
                if(i-mark+1>=2) cc.push_back(make_pair(i,i-mark+1));
                mark=i+1;
                i++;
            }
        }
        //for(int i=0;i<cc.size();i++) cout<<cc[i].first<<' '<<cc[i].second<<endl;
        if(cc.empty()) return 0;
        for(int j=0;j<cc.size();j++){
            int f=cc[j].first,k=f;
            while(A[k]>A[k+1]&&k+1<n){
                k++;
            }
            ans=max(ans,cc[j].second+k-f);
        }
        if(ans>=3) return ans;
        else return 0;
    }
};