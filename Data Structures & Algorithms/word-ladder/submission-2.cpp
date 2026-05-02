class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>wordListSet;
        for(auto w:wordList){
            wordListSet.insert(w);
        }

        queue<string>q;
        if(!wordListSet.count(endWord)) {
            return 0;
        }

        int steps=0;
        q.push(beginWord);

        while(!q.empty()) {
            int qsz = q.size();
            steps++;
            while(qsz--) {
                auto curr = q.front();
                 wordListSet.erase(curr);
                q.pop();
                for(int i=0;i<curr.size();i++) {
                    for(char nc='a';nc<='z';nc++) {
                        string ncurr = curr;
                        ncurr[i]=nc;
                        if(wordListSet.count(ncurr) ) {
                            q.push(ncurr);
                           
                            if(ncurr==endWord) {
                                return steps+1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};
