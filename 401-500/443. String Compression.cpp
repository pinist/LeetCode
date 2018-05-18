/*
Given an array of characters, compress it in-place.
The length after compression must always be smaller than or equal to the original array.
Every element of the array should be a character (not int) of length 1.
After you are done modifying the input array in-place, return the new length of the array.
 */
class Solution {  
public:  
    int compress(vector<char>& chars) {  
        int ans=0,i=0,n=chars.size();
        while(i<n){
            if(chars[i]!=chars[i+1]||i==n-1){
                chars[ans++]=chars[i++];
            }
            else{
                chars[ans++]=chars[i];
                int mark=i;
                while(chars[i]==chars[mark]&&i<n){
                    i++;
                }
                //cout<<i-mark;
                
                string s=to_string(i-mark);
                for(auto c:s) chars[ans++]=c;
            }
        }
        return ans;
    } 
    
}; 
