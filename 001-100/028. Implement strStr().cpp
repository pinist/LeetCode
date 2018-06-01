/*
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
 */
class Solution {
public:
    vector<int> nxt;
    void get(vector<int>& nxt,string ned){
        int j=-1,i=0;
        nxt[0]=-1;
        int n=ned.length();
        while(i<n){
            while(j!=-1&&ned[i]!=ned[j])
                j=nxt[j];
            
            nxt[++i]=++j;
        }
        return ;
    }
    
    int kmp(string hay,string ned,vector<int>& nxt){
        int n=hay.length(),m=ned.length();
        int i=0,j=0;
        while(i<n){
            while(j!=-1&&hay[i]!=ned[j])
                j=nxt[j];
            i++;j++;
            if(j==m) return i-j;
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        int m=needle.length();
        int n=haystack.length(); 
        if(n!=0&&m==0) return 0;
        if(m==0&&n==0) return 0;
        if(n==0&&m!=0) return -1;
        nxt.assign(m+1,0);
        get(nxt,needle);
        return kmp(haystack,needle,nxt);
    }
};