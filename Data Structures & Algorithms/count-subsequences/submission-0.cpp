class Solution {
public:
    int dp[1001][1001];
    int solve(string s,string t,int n1,int n2) {
        if(!n2){
            return 1;
        }

        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(!n1 && n2) {
            return 0;
        }
        
        int ans = 0;
        if(s[n1-1]==t[n2-1]) {
            ans=solve(s,t,n1-1,n2-1);
        }
        ans+=solve(s,t,n1-1,n2);
        return dp[n1][n2]=ans;
    }
    int numDistinct(string s, string t) {
           for(int i=0;i<=1000;i++) {
            for(int j=0;j<=1000;j++){
                dp[i][j]=-1;
            }
        }
        return solve(s,t,s.size(),t.size());
    }
};