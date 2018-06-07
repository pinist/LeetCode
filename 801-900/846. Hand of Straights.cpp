/*
Alice has a hand of cards, given as an array of integers.
Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
Return true if and only if she can.
 
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W) return false;
        map<int,int>cnt;
        for(auto it:hand) cnt[it]++;
        
        while(!cnt.empty()){
            int x=cnt.begin()->first;
            for(int i=0;i<W;++i){
                if(!cnt.count(x+i)) return false;
                if(--cnt[x+i]==0) cnt.erase(x+i);
            }
        }
        return true;
    }
};