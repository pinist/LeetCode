/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Return a list of all uncommon words. 
You may return the list in any order.
*/
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string,int> ma;
        stringstream s(A);
        string str;
        while(s>>str)
        {
            ma[str]++;
        }
        stringstream ss(B);
        while(ss>>str){
            ma[str]++;
        }
        vector<string> res;
        for(auto tt:ma){
            if(tt.second==1) res.push_back(tt.first);
        }
        return res;
    }
    
};