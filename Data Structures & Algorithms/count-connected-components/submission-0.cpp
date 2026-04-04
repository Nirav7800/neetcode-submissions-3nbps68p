class Solution {
public:
    void dfs(int u, unordered_map<int,vector<int>>&mp, vector<int>&vis) {
        vis[u]=1;
        for(auto v : mp[u]) {
            if(!vis[v]) {
                dfs(v,mp,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto i:edges) {
            int u = i[0];
            int v = i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int ans = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                ans++;
                dfs(i,mp,vis);
            }
        }
        return ans;
    }
};
