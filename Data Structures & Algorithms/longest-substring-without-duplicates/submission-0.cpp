class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int p1=0;
        int p2=0;
        int ans = 0;
        while(p2<n) {
            mp[s[p2]]++;
            while(mp.size()!=(p2-p1+1)){
                mp[s[p1]]--;

                if(mp[s[p1]]==0) mp.erase(s[p1]);
                p1++;
            }
            ans = max(ans,p2-p1+1);
            p2++;
        }
        return ans;
    }
};
