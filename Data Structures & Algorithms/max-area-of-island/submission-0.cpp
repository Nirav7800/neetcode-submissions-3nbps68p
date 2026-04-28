class Solution {
private:
    int DFS(vector<vector<int>>& grid,int i,int j,int c,int r, vector<vector<int>>& visited)
    {
        if(i<0 or j<0 or i>=r or j>=c or visited[i][j]==1) return 0;
        visited[i][j]=1;
        if(grid[i][j]==1){
            return 1+DFS(grid,i+1,j,c,r,visited)
                    +DFS(grid,i-1,j,c,r,visited)
                    +DFS(grid,i,j-1,c,r,visited)
                    +DFS(grid,i,j+1,c,r,visited);}
        else
            return 0;
    }
public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        if(r==0) return 0;
        int c=grid[0].size();
        int max_size=0;
        vector<vector<int>>visited(r,vector<int>(c,0));
                                for(int i=0;i<r;i++)
                                   {
                                       for(int j=0;j<c;j++)
                                       { int res=0;
                                           res=DFS(grid,i,j,c,r,visited);
                                           if(res){ max_size=max(max_size,res);}
                                              
                                       }
                                   }
                                   return max_size;
        }
};
