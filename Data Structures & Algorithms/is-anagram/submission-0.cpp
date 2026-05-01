class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m) return false;

        unordered_map<char,int>mp;

        for(auto i:s) {
            mp[i]++;
        }

        for(auto i:t) {
            if(mp.find(i)==mp.end()) return false;
            mp[i]--;
            if(mp[i]==0) mp.erase(i);
        }

        return mp.size()==0;
    }
};