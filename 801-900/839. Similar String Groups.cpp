/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.
For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
We are given a list A of unique strings.  Every string in A is an anagram of every other string in A.  How many groups are there?
 */
class Solution {
public:
    int uf[2005];
    int find(int x){
        return x==uf[x]?x:uf[x]=find(uf[x]);
    }
    
    void merge(int a, int b){
        int ua=find(a),ub=find(b);
        if(ua!=ub) uf[ub]=ua;
    }
    
    int getgroup(int n){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(uf[i]==i) cnt++;
        return cnt;
    }
    
    bool issimilar(string A,string B){
        int alen=A.length(),blen=B.length();
        int cnt=0;
        if(alen!=blen) return false;       
        else{
            for(int i=0;i<alen;i++){
                if(A[i]!=B[i]) cnt++;
            }
        }
        return cnt==2;
    }
    
    int numSimilarGroups(vector<string>& A) {
        int n=A.size();
        if(!n) return 0;
        for(int i=1;i<=n;i++) uf[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(issimilar(A[i],A[j])) merge(i+1,j+1);
            }
        }
        return getgroup(n);
        
    }
};