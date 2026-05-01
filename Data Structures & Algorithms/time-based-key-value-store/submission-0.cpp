class TimeMap {
private:
  string findIdx(vector<pair<int,string>>nums, int timestamp) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    string ans = "";
    while(lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if(nums[mid].first==timestamp) return nums[mid].second;
        else if(nums[mid].first<timestamp){
            ans = nums[mid].second;
            lo = mid+1;
        }else {
            hi = mid-1;
        }
    }
    return ans;
  }
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        sort(mp[key].begin(),mp[key].end());
    }
    
    string get(string key, int timestamp) {
        return findIdx(mp[key],timestamp);
        
    }
};
