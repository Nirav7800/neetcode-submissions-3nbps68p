class Solution {
public:
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    int n,m;
    void dfs(vector<vector<char>>& board,int x,int y) {
        board[x][y]='N';
        for(int k=0;k<4;k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]=='O')
            dfs(board,nx,ny);
        }
    }
    void solve(vector<vector<char>>& board) {
         n = board.size();
         m = board[0].size();
        for(int i=0;i<m;i++) {
            if(board[0][i]=='O')
            dfs(board,0,i);
        }
        //last col
        for(int i=0;i<n;i++) {
            if(board[i][m-1]=='O')
            dfs(board,i,m-1);
        }

        for(int i=0;i<m;i++) {
            if(board[n-1][i]=='O')
            dfs(board,n-1,i);
        }

        for(int i=0;i<n;i++) {
            if(board[i][0]=='O')
            dfs(board,i,0);
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='N') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};
