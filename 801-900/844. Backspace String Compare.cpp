/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. 
# means a backspace character.
 */

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n=S.length(),m=T.length();
        string A;string B;
        if(!m&&!n) return true;
        for(int i=0;i<n;i++){
            if(S[i]>='a'&&S[i]<='z') A+=S[i];
            else{
                if(A.empty()==false) A.erase(A.end()-1);
            }

        }
        for(int j=0;j<m;j++){            
            if(T[j]>='a'&&T[j]<='z') B+=T[j];
            else{
                if(B.empty()==false) B.erase(B.end()-1);
            }  
            
        }
        return A==B;
    }
};