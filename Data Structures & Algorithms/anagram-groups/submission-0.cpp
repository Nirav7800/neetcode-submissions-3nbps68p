class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         int n = strs.size();

        unordered_map<string,vector<string>>mp;
        
        vector<vector<string>>ans;

        for(auto i : strs) {
            string curr = i;
            sort(curr.begin(),curr.end());
            mp[curr].push_back(i);
        }

        for(auto i:mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
