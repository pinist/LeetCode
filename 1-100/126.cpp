/*Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
*/

/*
Idea: set up one map from endWord to beginWord via bfs.Then using dfs from beginWord to endWord,guaranteeing the depth 
of next node equals current node.
 */
class Solution {
public:
    bool one(string a, string b){
        int cnt=0;
        for(int i=0;i<a.size();i++) cnt+=(a[i]!=b[i]);
        return cnt==1;
    }
    
    queue<int > qu;    
    vector<vector<string> > ans;
    vector<string> tmp;
    
    string beginWord;
    vector<string> wordList;
    int end=-1;
    vector<int>d;
    vector<vector<int> >g;
    
    void bfs(){
        d[end]=0;
        qu.push(end);
        while(!qu.empty()){
            int u=qu.front(); qu.pop();
            for(auto v:g[u]){
                if(d[v]==-1) {
                    qu.push(v);
                    d[v]=d[u]+1;}
            }
        }
        //return;
    }
    int n;
    void dfs(int dep, int u){
        tmp[dep]=(u==n?beginWord:wordList[u]);
        if(u==end){
            ans.push_back(tmp);
            return;
        }
        
        for(auto v:g[u]){
            if(d[v]==d[u]-1) dfs(dep+1,v);
        }
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        n=wordList.size();
        this->wordList=wordList; this->beginWord=beginWord;
        if(!n) return ans;
        d.assign(n+1,-1);
        g.assign(n+1,vector<int>());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(one(wordList[i],wordList[j])){
                    g[i].push_back(j);g[j].push_back(i);
                }
            }
            if(one(wordList[i],beginWord)) {
                g[n].push_back(i);g[i].push_back(n);
            }
            if(wordList[i]==endWord) end=i;
        }
        if(end==-1) return ans;
        cout<<end<<endl;
        bfs();
        if(d[n]==-1) return ans;
        tmp.assign(d[n]+1," ");
        dfs(0,n);
        return ans;
    }
        
    
};