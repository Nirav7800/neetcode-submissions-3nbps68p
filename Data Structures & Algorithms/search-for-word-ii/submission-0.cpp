class Solution {
public:
    int n,m;
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    void dfs(vector<vector<char>>& board,int i,int j,string curr,unordered_set<string>&st,int&max_len,vector<string>&ans,vector<vector<int>>vis){
         if(st.count(curr)) {
            ans.push_back(curr);
            st.erase(curr);
         }
         if(curr.size()>max_len) {
            return;
         }

         for(int k=0;k<4;k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny]){
                vis[nx][ny]=1;
                dfs(board,nx,ny,curr+board[nx][ny],st,max_len,ans,vis);
                vis[nx][ny]=0;
            }
         }

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         n = board.size();
         m = board[0].size();
        unordered_set<string>st;
        vector<string>ans;
        int max_len = 0;
        for(auto i:words){
            st.insert(i);
            int c = i.size();
            max_len = max(max_len,c);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                vector<vector<int>>vis(n,vector<int>(m,0));
                vis[i][j]=true;
                string curr = "";
                curr.push_back(board[i][j]);
                dfs(board,i,j,curr,st,max_len,ans,vis);
            }
        }
        return ans;
    }
};
