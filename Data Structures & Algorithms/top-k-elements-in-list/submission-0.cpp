class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minH;
        for(auto i:mp){
            minH.push({i.second,i.first});
            if(minH.size()>k) minH.pop();
        }
        vector<int>ans;
        while(!minH.empty()) {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }

};
