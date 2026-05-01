class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dx = {1,-1,0,0};
        vector<int>dy = {0,0,1,-1};
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=grid[0][0];
        q.push({0,0});
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int i=0;i<4;i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                //check for valid
                if(nx>=0 && ny>=0 && nx<n && ny<m && dis[nx][ny]>max(dis[x][y],grid[nx][ny])) {
                    q.push({nx,ny});
                    dis[nx][ny]=max(dis[x][y],grid[nx][ny]);
                }
            }
            
        }
        return dis[n-1][m-1];
    }
};
