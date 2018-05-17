/*Implement a trie with insert, search, and startsWith methods.*/
class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        bool word;
        TrieNode* son[26];
        TrieNode():word(0){
            for(int i=0;i<26;i++){
                son[i]=NULL;
            }
        }
    };
    TrieNode *root;
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur=root;
        for(auto c:word){
            if(cur->son[c-'a']==NULL)
                cur->son[c-'a']=new TrieNode();
            cur=cur->son[c-'a'];
        }
        cur->word=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur=root;
        for(auto c:word){
            if(cur->son[c-'a']==NULL) return 0;
            cur=cur->son[c-'a'];
        }
        return cur->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char c:prefix){
            if(cur->son[c-'a']==NULL) return 0;
            cur=cur->son[c-'a'];
        }
        return 1;
    }
};

