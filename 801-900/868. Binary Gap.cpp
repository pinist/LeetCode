/*
Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.
If there aren't two consecutive 1's, return 0.
 */
class Solution {
public:
    int binaryGap(int N) {
        vector<int> bi;
        int t=N;
        while(t){
            bi.push_back(t%2);
            t=t/2;
        }
        int ans=0,mark=-1;
        int n=bi.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mark==-1 && bi[i]==1) {
                mark=i;
                cnt++;
            }
            if(mark!=-1 && bi[i]==1){
                ans=max(ans,i-mark);
                mark=i;
                cnt++;
            }
        }
        return cnt==1?0:ans;
    }
};