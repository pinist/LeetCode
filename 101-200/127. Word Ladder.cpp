class Solution {
public:
    bool one(string a, string b){
        int cnt=0;
        for(int i=0;i<a.size();i++) cnt+=(a[i]!=b[i]);
        return cnt==1;
    }
    
    map <string, int> dis;
    queue<string> qu;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {                      
        int Lsize=wordList.size();
        int f=-1;
        for(int i=0;i<Lsize;i++) {
            if(wordList[i]==endWord) f=i;
        }
        if(f==-1) return 0;
        qu.push(beginWord);dis[beginWord]=1;
        while(!qu.empty()){
            string tmp=qu.front();qu.pop();
            for(int i=0;i<Lsize;i++){
                
                if(one(tmp,wordList[i])&&dis.find(wordList[i])==dis.end()){
                    dis[wordList[i]]=dis[tmp]+1;
                    qu.push(wordList[i]);
                    if(wordList[i]==endWord) return dis[endWord];
                }
            }
        }
        return dis[endWord];
    }
};
