class Solution {
public:
    string findparent(unordered_map<string,string>&par,string p){
        if(par[p]==p) return p;
        return par[p]=findparent(par,par[p]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<string,string>par;
        priority_queue<pair<int,pair<string,string>>,vector<pair<int,pair<string,string>>>,greater<pair<int,pair<string,string>>>>minH;
        for(int i=0;i<n;i++) {
            int xi = points[i][0];
            int yi = points[i][1];
            string p1 = to_string(xi)+","+to_string(yi);
            par[p1]=p1;
            for(int j=i+1;j<n;j++) {
                int xj = points[j][0];
                int yj = points[j][1];
                int dis = abs(xi-xj)+abs(yi-yj);
                string p2 = to_string(xj)+","+to_string(yj);
                minH.push({dis,{p1,p2}});
            }
        }

        int cost = 0;
        while(!minH.empty()){
            auto curr = minH.top();
            minH.pop();
            string p1 = curr.second.first;
            string p2 = curr.second.second;
            string pp1 = findparent(par,p1);
            string pp2 = findparent(par,p2);
            if(pp1!=pp2) {
                cost+=curr.first;
                par[pp1]=pp2;
            }
        }
        return cost;

    }
};
