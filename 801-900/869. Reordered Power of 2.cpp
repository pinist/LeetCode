/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.
Return true if and only if we can do this in a way such that the resulting number is a power of 2.
*/
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        map<string,int> ma;
        for(int i=0;i<=30;i++){
            int a=1<<i;
            string tmp=to_string(a);
            sort(tmp.begin(),tmp.end());
            ma[tmp]=1;
        }
        
        int t=N; string cm;
        while(t){
            cm+=to_string(t%10);
            t/=10;
        }
        
        sort(cm.begin(),cm.end());
        cout<<cm;
        if(ma.find(cm)==ma.end()) return false;
        else return true;
    }
};