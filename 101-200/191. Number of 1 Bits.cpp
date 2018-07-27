/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        for(int i=0;i<32;i++){
            if(n&1<<i) cnt++;
        }
        return cnt;
    }
};