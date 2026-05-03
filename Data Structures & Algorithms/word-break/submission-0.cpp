class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordDictSet;
        for(auto i:wordDict) {
            wordDictSet.insert(i);
        }
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[n]=true;
        for(int i=n-1;i>=0;i--) {
            string curr = "";
            for(int j=i;j<n;j++) {
                curr+=s[j];
                if(wordDictSet.count(curr) && dp[j+1]) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
