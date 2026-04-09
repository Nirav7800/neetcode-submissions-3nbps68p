class Solution {
public:
     int dp[101];
    int solve(string s,int n) {
        if(n==0) {
            return 1;
        }
        int ans = 0;
        if(dp[n]!=-1) return dp[n];
        if(s[n-1]!='0')
        ans +=solve(s,n-1);
        if(n>=2) {
            string curr = s.substr(n-2,2);
            if(s[n-2]!='0' && curr<="26")
            ans+=solve(s,n-2);
        }
        return dp[n]=ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        for(int i=0;i<=100;i++) dp[i]=-1;
        return solve(s,n);
    }
};
