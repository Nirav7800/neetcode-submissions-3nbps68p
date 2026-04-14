class Solution {
public:
    int dp[101][101];
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    int dfs(int i,int j,vector<vector<int>>& matrix) {
        int ans = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m && matrix[i][j]<matrix[nx][ny]){
                ans = max(ans,1+dfs(nx,ny,matrix));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j]=-1;
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dp[i][j]==-1) {
                    dfs(i,j,matrix);
                }
            }
        }
        int ans = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;


    }
};
