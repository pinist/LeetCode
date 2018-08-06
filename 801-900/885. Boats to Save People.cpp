/*
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.
Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        sort(a.begin(),a.end());
	    int n=a.size();
	    int p=0;
	    int ct=0;
	    for(int i=n-1;i>=p;i--){
	        if(p<i&&a[i]+a[p]<=limit) p++;
	        ct++;
	    }
	    return ct;
    }
};