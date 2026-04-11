class Solution {
public:
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    int n,m;
    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>&sea,vector<vector<bool>>&vis ){
        vis[i][j]=true;
        sea[i][j]=true;
        for(int k=0;k<4;k++) {
            int nx = dx[k]+i;
            int ny = dy[k]+j;
            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && heights[nx][ny]>=heights[i][j]) {
                dfs(heights,nx,ny,sea,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         n = heights.size();
         m = heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,0));
        vector<vector<bool>>atlantic(n,vector<bool>(m,0));
        vector<vector<bool>>vis1(n,vector<bool>(m,0));
         vector<vector<bool>>vis2(n,vector<bool>(m,0));
        //traverse from pacific 
        //first row
        for(int c=0;c<m;c++) {
            if(!vis1[0][c]) {
                dfs(heights,0,c,pacific,vis1);
            }
        }
        //first col
        for(int r=0;r<n;r++) {
            if(!vis1[r][0]) {
                 dfs(heights,r,0,pacific,vis1);
            }
        }

        //traverse from atlantic
        //last col
        for(int r=0;r<n;r++) {
            if(!vis2[r][m-1]){
                dfs(heights,r,m-1,atlantic,vis2);
            }
        }

        //last row
        for(int c=0;c<m;c++) {
            if(!vis2[n-1][c]) {
                 dfs(heights,n-1,c,atlantic,vis2);
            }
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
