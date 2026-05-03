class Solution {
public:
    // int dp[1001][1001];
    // int solve(string s,string t,int n1,int n2) {
    //     if(!n2){
    //         return 1;
    //     }

    //     if(dp[n1][n2]!=-1) return dp[n1][n2];
    //     if(!n1 && n2) {
    //         return 0;
    //     }
        
    //     int ans = 0;
    //     if(s[n1-1]==t[n2-1]) {
    //         ans=solve(s,t,n1-1,n2-1);
    //     }
    //     ans+=solve(s,t,n1-1,n2);
    //     return dp[n1][n2]=ans;
    // }
    int numDistinct(string s, string t) {
        // memset(dp,-1,sizeof(dp));
        // return solve(s,t,s.size(),t.size());
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++){
           for(int j=0;j<=m;j++) {
                if(j==0) {
                    dp[i][j]=1;
                }
           }
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j];
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};