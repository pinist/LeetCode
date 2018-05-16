/*
Implement int sqrt(int x).
 */
class Solution {

public:
    int mySqrt(int x) {
        if (x==0) {
            return 0;
        }
        int start=0,end=x;
        while(start+1<end){
            int mid=start+(end-start)/2;
            if(x/mid==mid) return mid;
            else if(x/mid>mid) start=mid;
            else end = mid;
        }
        if(x/end==end) return end;
        return start;
    }
};
