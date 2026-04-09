class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>maxH;
        for(auto i:points) {
            int x = i[0];
            int y = i[1];
            double d = sqrt(x*x+y*y);
            maxH.push({d,{x,y}});
            if(maxH.size()>k) maxH.pop();
        }
        vector<vector<int>>ans;
        while(!maxH.empty()) {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};
