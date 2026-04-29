class Solution {
private:
int findParent(int n,vector<int>&par) {
        if(n==par[n]) return n;
        return par[n]=findParent(par[n],par);
    }
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
       vector<int>par(n+1);
        for(int i=1;i<=n;i++) {
            par[i]=i;
        }
        vector<int>ans;
        for(auto i:edges) {
            int u = i[0];
            int v = i[1];
            int pu = findParent(u,par);
            int pv = findParent(v,par);
            if(pu==pv) {
                ans={u,v};
            }
            if(pu<pv) {
                par[pv]=pu;
            } else {
                par[pu]=pv;
            }
        }
        return ans;
    }
};
