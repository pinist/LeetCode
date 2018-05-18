/*
There are N students in a class. Some of them are friends, while some are not.
Their friendship is transitive in nature. For example, if A is a direct friend of B, 
and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect friends.
Given a N*N matrix M representing the friend relationship between students in the class. 
If M[i][j] = 1, then the ith and jth students are direct friends with each other, 
otherwise not. And you have to output the total number of friend circles among all the students.
 */

class Solution {
public:
    int vec[210];
    void init(int size){
        for(int i=1;i<=size;i++){
            vec[i]=i;
        }
    }
    int find(int x){
        return x==vec[x]?x:vec[x]=find(vec[x]);
    }
    
    int merge (int a,int b){
        int fa=find(a);
        int fb=find(b);
        if(fa!=fb){
            vec[fb]=fa;
        }
        return fa;
    }
    
    int cnt(int size){
        int sum=0;
        for(int i=1;i<=size;i++){
            if(vec[i]==i){
                sum++;                
            }
        }
        return sum;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int size=M[0].size();
        init(size);
        for(int i=0;i<size;i++){
            for(int j=i;j<size;j++){
                if(M[i][j])  merge(i+1,j+1);
            }
        }
        int re=cnt(size);
        return re;       
    }
};