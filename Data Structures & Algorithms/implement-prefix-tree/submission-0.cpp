struct TrieNode {
    bool isEndOfWord;
    TrieNode* child[26];
    TrieNode() {
        isEndOfWord = false;
        for(int i=0;i<26;i++) {
            child[i]=NULL;
        }
    }
};

class PrefixTree {
public:
   TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto c:word){
            if(!curr->child[c-'a']) {
                curr->child[c-'a']=new TrieNode();
            }
            curr = curr->child[c-'a'];
        }
        curr->isEndOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c:word){
            if(!curr->child[c-'a']) {
               return false;
            }
            curr = curr->child[c-'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c:prefix){
            if(!curr->child[c-'a']) {
               return false;
            }
            curr = curr->child[c-'a'];
        }
        return true;
    }
};
