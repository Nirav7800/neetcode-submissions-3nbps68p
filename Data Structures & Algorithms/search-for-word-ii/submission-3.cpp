struct TrieNode{
    int isEndWord;
    int freq;
    TrieNode* child[26];
     TrieNode(){
        for(int i=0;i<26;i++) {
            child[i]=NULL;
        }
        freq = 0;
        isEndWord = 0;
    }

};


class Solution {
public:
    TrieNode* root=new TrieNode();
    int n,m;
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    void dfs(vector<vector<char>>& board,int x,int y,TrieNode* node,string curr, vector<string>&ans,vector<vector<int>>&vis) {
        if(x>=n || y>=m || x<0 || y<0 || vis[x][y] || !node->child[board[x][y]-'a']) {
            return;
        }
        curr+=board[x][y];
        // node->child[board[x][y]-'a']->freq--; 
        if(node->child[board[x][y]-'a']->isEndWord){
            node->child[board[x][y]-'a']->isEndWord--;
            ans.push_back(curr);
        }
        node = node->child[board[x][y]-'a'];
     vis[x][y]=1;
        for(int k=0;k<4;k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            
            dfs(board,nx,ny,node,curr,ans,vis);
            
        }
        vis[x][y]=0;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto w:words) {
            auto curr = root;
            for(auto c:w) {
                if(!curr->child[c-'a']) {
                    curr->child[c-'a']=new TrieNode();
                }
                curr=curr->child[c-'a'];
                curr->freq++;
            }
            curr->isEndWord=true;
        }

        n=board.size();
        m=board[0].size();
        vector<string>ans;

        for(int i=0;i<n;i++) {
          
            for(int j=0;j<m;j++) {
                vector<vector<int>>vis(n,vector<int>(m,0));
                auto curr = root;
                dfs(board,i,j,curr,"",ans,vis);
            }
        }
        return ans;
    }
};
