class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n<m) return "";
        string ans="";
        unordered_map<char,int>mpt;
        unordered_map<char,int>mps;
        for(auto c:t) {
            mpt[c]++;
        }
        int p1 = 0;
        int p2 = 0;
        int count = 0;
        while(p2<n) {
            if(mpt.count(s[p2])) {
                mps[s[p2]]++;
                if(mps[s[p2]]==mpt[s[p2]]) count++;
            }
            while(p1<=p2 && count==mpt.size()) {
                if(ans.size()>(p2-p1+1) || ans=="") {
                    ans = s.substr(p1,p2-p1+1);
                }
                if(mpt.count(s[p1])) {
                    if(mpt[s[p1]]==mps[s[p1]]) count--;
                    mps[s[p1]]--;
                }
                p1++;
            }
            p2++;
        }
        return ans;
    }
};
