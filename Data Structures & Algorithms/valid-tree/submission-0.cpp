class Solution {
public:
    bool dfs(int u, unordered_map<int,vector<int>>&mp, vector<int>&vis, int par) {
        vis[u]=true;
        for(auto v:mp[u]) {
            if(par==v) {
                continue;
            }
            if(vis[v]) return false;
            if(!dfs(v,mp,vis,u)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
       int m = edges.size();
       if(m!=n-1) {
        return false;
       }
       //check if cycle;
       unordered_map<int,vector<int>>mp;
       for(auto i:edges) {
        int u = i[0];
        int v = i[1];
        mp[u].push_back(v);
        mp[v].push_back(u);
       }
       vector<int>vis(n,0);
       if(!dfs(0,mp,vis,-1)) {
          return false;
       }
       for(int i=0;i<n;i++) {
         if(!vis[i]) {
            return false;
         }
       }
       return true;
    }
};
