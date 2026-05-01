class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue< pair<int,int> >q;

        int n = grid.size();
        int m = grid[0].size();
        int noOfFreshorange = 0;

        for(int i=0;i<n;i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                } else if(grid[i][j]==1) {
                    noOfFreshorange++;
                }
            }
        }

        if(!noOfFreshorange) return 0;

        int time = 0;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!q.empty()) {
            int sz = q.size();
            time++;
            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        noOfFreshorange--;
                    }
                }
            }
        }

        if(noOfFreshorange) return -1;
        return time-1;
    }
};