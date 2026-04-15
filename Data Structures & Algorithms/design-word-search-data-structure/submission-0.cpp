struct Trie{
    bool endofWord;
    Trie* child[26];
    Trie() {
        endofWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        cout<<word<<endl;
        Trie* curr = root;
        for(auto c:word) {
            if(!curr->child[c-'a']){
                curr->child[c-'a']=new Trie();
            } 
            curr = curr->child[c-'a'];
        }
        curr->endofWord = true;
    }
    bool searchHelper(Trie* curr, string word, int i) {
        if(i==word.size()) return curr->endofWord;
        if(word[i]!='.' && curr->child[word[i]-'a']) return searchHelper(curr->child[word[i]-'a'],word,i+1);
        else if(word[i]=='.') {
           for(int k=0;k<26;k++) {
                if(curr->child[k] && searchHelper(curr->child[k],word,i+1)) return true;
            }
        }  
        return false;
    }
    bool search(string word) {
        cout<<word<<endl;
        Trie* curr = root;
       return searchHelper(curr,word,0);
    }
};
