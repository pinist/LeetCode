/*
Implement pow(x, n), which calculates x raised to the power n.
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
 */
class Solution {
public:
    double myPow(double x, int n) {
        long m=n;
        if(m<0){
            x=1/x;
            m=-m;
        }
        double a=1;
        while(m>0){
            if(m&1)a*=x;
            x*=x;
            m>>=1;
        }
        return a;
    }
};