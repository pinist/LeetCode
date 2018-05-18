class Solution {
public:
    bool istrue(int n){
        bool f=0;
        while(n>0){
            int a=n%10;
            if(a==3||a==4||a==7){
                return false;
            }
            if(a==2||a==5||a==6||a==9) f=true;
            n/=10;
        }
        return f;
    }
    int rotatedDigits(int N) {
        int sum=0;
        for(int i=0;i<=N;i++){
            if(istrue(i)) sum++;
        }
        return sum;
    }
};