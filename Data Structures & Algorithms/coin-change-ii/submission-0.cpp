class Solution {
public:
    int dp[301][5001];
    int solve(vector<int>& coins,int amount,int i,int n) {
        if(amount==0) {
            return 1;
        }
        if(i==n) {
            return 0;
        }
        int ans = 0;
        if(dp[i][amount]!=-1) return dp[i][amount]; 
        if(amount>=coins[i]) {
            ans = solve(coins,amount-coins[i],i,n);
        }
        ans+=solve(coins,amount,i+1,n);
        return dp[i][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        for(int i=0;i<=100;i++) {
            for(int j=0;j<=5000;j++) {
                dp[i][j]=-1;
            }
        }
        return solve(coins,amount,0,coins.size());
    }
};
