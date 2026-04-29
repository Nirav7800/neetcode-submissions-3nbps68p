class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto e:times) {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            adj[u].push_back({v,t});
        }
        vector<int>time(n+1,INT_MAX);
        queue<int>q;
        time[k]=0;
        q.push(k);
        int minimum_time=0;
        while(!q.empty()) {
            int currV = q.front();
            q.pop();
            //check adj lists
            for(auto v:adj[currV]) {
                int node = v.first;
                int t = v.second;
                if(t+time[currV]<time[node]) {
                  
                    time[node]=t+time[currV];
                    q.push(node);
                }
            }
        }

        for(int i=1;i<=n;i++) {
            if(time[i]==INT_MAX) return -1;
            minimum_time=max(minimum_time,time[i]);
        }
        return minimum_time;
    }
};
