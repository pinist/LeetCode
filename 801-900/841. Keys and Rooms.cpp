/*
There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 
Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
Initially, all the rooms start locked (except for room 0). 
You can walk back and forth between rooms freely.
Return true if and only if you can enter every room.
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        if(!n) return false;
        vector<int> vis(n,0);
        queue<int>qu;
        qu.push(0);
        while(!qu.empty()){
            int tmp=qu.front();qu.pop();
            vis[tmp]=1;
            for(auto v:rooms[tmp]){
                if(!vis[v]) {
                    qu.push(v);
                    vis[v]=1;
                }
            }
        }
        bool f=true;
        for(int i=0;i<n;i++){
            if(!vis[i]) f=false;
        }
        return f;
    }
};