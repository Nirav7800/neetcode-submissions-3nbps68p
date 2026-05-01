class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>dist(n,INT_MAX);
        vector<int>vis(n,0);

        int node = 0;
        int edge = 0;
        int cost = 0;
        while(edge<n-1) {
           vis[node]=true;
           int nextNode = -1;
           for(int i=1;i<n;i++) {
             if(vis[i]) continue;
             int curr_cost = abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
             dist[i]=min(dist[i],curr_cost);
             if(nextNode==-1 || dist[i]<dist[nextNode]) {
                nextNode = i;
             }
           }
           
             node = nextNode;
             cost+=dist[nextNode];
             edge++;
        }
        return cost;
    }
};
