class Solution {
public:
    // int dp[11][10001];
    // int solve(vector<int>&coins, int n,int amount){
    //     if(amount==0) {
    //         return 0;
    //     }

    //     if(n==0) {
    //         return INT_MAX-1;
    //     }
    //     if(dp[n][amount]!=-1) {
    //         return dp[n][amount];
    //     }

    //     //take
    //     int total=INT_MAX-1;
    //     if(coins[n-1]<=amount) {
    //          total=1+solve(coins,n,amount-coins[n-1]);
    //     }
    //     //skip
    //     total=min(total,solve(coins,n-1,amount));
    //     return  dp[n][amount]=total;
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // for(int i=0;i<=10;i++) {
        //     for(int j=0;j<=10000;j++) {
        //         dp[i][j]=-1;
        //     }
        // }
        // int coinsneeded = solve(coins,n,amount);
        
        // return coinsneeded==INT_MAX-1?-1:coinsneeded;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=amount;j++) {
                if(j==0) {
                    dp[i][j]=0;
                } else if(i==0) {
                    dp[i][j]=INT_MAX-1;
                } else {
                    dp[i][j]=dp[i-1][j];
                    if(j>=coins[i-1]) {
                        dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i-1]]);
                    }
                }
            }
        }
        return dp[n][amount]>=INT_MAX-1?-1:dp[n][amount];
    }
};
