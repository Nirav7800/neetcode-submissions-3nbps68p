class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0) {
                    q.push({i,j});
                }
            }
        }

        vector<int>dx = {1,-1,0,0};
        vector<int>dy = {0,0,1,-1};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            for(int k=0;k<4;k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==INT_MAX) {
                    q.push({nx,ny});
                    grid[nx][ny]=1+grid[i][j];
                }
            }
        }
    }
};
