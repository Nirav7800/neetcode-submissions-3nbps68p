class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>> > mp;
        for(auto i:flights) {
            int u = i[0];
            int v = i[1];
            int d = i[2];
            mp[u].push_back({v,d});
        }

        vector<int>dis(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src]=0;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            int nn = curr.second;
            if(nn>k) continue;
            for(auto v:mp[node]) {
                if(dis[node]+v.second<dis[v.first] && (v.first==dst || nn+1<=k)) {
                    dis[v.first]=dis[node]+v.second;
                    if(v.first==dst) continue;
                    q.push({v.first,nn+1});
                }
            }
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};
