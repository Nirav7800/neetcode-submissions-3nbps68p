class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 1;
        int max_freq = 1;
        unordered_map<char,int>mp;
        int p1 =0;
        int p2 =0;
        while(p2<n) {
            mp[s[p2]]++;
            max_freq = max(max_freq,mp[s[p2]]);
            while((p2-p1+1-max_freq)>k){
                mp[s[p1]]--;
                p1++;
            }
            ans = max(ans,p2-p1+1);
            p2++;
        }
        return ans;
    }
};
