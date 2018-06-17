/*
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
There is at least one empty seat, and at least one person sitting.
Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
Return that maximum distance to closest person.
 */
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int idx=-1,res=0;
        int n=seats.size();
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                if(idx==-1) res=max(res,i-idx-1);
                else res=max(res,(i-idx)/2);
                idx=i;
            }
        }
        res=max(res,n-idx-1);
        return res;
    }
};