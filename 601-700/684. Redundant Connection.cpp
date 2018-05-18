class Solution {
public:
    int uf[2005];
    void init(){
        for(int i=0;i<2005;i++){
            uf[i]=i;
        }
    }
    int find(int x){
        return x==uf[x]?x:uf[x]=find(uf[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int si=edges.size();
        init();
        for(int i=0;i<si;i++){
            int p1=find(edges[i][0]);
            int p2=find(edges[i][1]);
            if(p1!=p2) uf[p2]=p1;
            else return edges[i];
        }
        return vector<int>(0,0);
    }
};