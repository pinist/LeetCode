solution1
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans=0;
        for(int k=2;(k*(k+1))/2<=N;k++){
            if((N-(1+k)*k/2)%k==0) ans++;    
        }
        return ans+1;
    }
};

solution 2
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans=0;
        for(int k=2;(k*(k+1))/2<=N;k++){
            for(int i=max(N/k-k/2,1),t=0;t<N;i++){
                t=(i-1)*k+(k*(k+1))/2;
                if(t==N) ans++;
            }       
        }
        return ans+1;
    }
};