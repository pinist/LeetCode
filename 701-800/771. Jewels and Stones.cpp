/*
You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have.
Each character in S is a type of stone you have.
You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive,
 so "a" is considered a different type of stone from "A".
 */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans=0;
        int m=J.length(),n=S.length();
        //cout<<n<<" "<<m<<" "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(J[j]==S[i]) ans++;
            }
        }
        return ans;
    }
};