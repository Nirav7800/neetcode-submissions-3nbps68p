class Solution {
public:
    vector<int>dx = {0,0,1,-1};
    vector<int>dy = {1,-1,0,0};
    bool dfs(vector<vector<char>>& board,int i,int j,int k, string word, vector<vector<int>>&vis) {
        if(k==word.size()) return true;
        for(int m=0;m<4;m++) {
            int nx = i+dx[m];
            int ny = j+dy[m];
            if(nx>=0 && ny>=0 && nx<board.size() && ny<board[0].size() && !vis[nx][ny] && board[nx][ny]==word[k]){
                vis[nx][ny]=1;
                if(dfs(board,nx,ny,k+1,word,vis)) return true;
                vis[nx][ny]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(n*m<word.size()) return false;
        for(int i=0;i<n;i++) {
            for(int j=0; j<m;j++) {
                if(board[i][j]==word[0]) {
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    if(dfs(board,i,j,1,word,vis)) {
                        vis[i][j]=1;
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
