class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        for(int k=0;k<4;k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]=='1'){
                dfs(grid,nx,ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // 2d grid
        // 0 rept water
        // 1 rept land
        // return no of island(formed by connecting land)
        int n = grid.size();
        int m = grid[0].size();
        int noOfIsland = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]=='1') {
                    noOfIsland++;
                    dfs(grid,i,j);
                }
            }
        }
        return noOfIsland;
    }
};
