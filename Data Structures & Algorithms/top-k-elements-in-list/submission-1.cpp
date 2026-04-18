class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>freqBucket(n+1);//max freq can be n for any ele
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        for(auto i:mp) {
            freqBucket[i.second].push_back(i.first);
        }
        vector<int>ans;
        for(int i=n;i>0;i--) {
            if(ans.size()==k) return ans;
            for(int e:freqBucket[i]) {
                ans.push_back(e);
            }
        }
        return ans;

    }
};
