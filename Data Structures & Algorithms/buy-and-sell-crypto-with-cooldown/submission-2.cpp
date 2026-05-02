class Solution {
public:
    int dp[5001][2][2];

    int solve(vector<int>& prices,int i,int n,bool iscooldown,bool holding) {
        if(i==n) return 0;

        if(dp[i][iscooldown][holding]!=-1) return dp[i][iscooldown][holding];

        // cooldown day
        if(iscooldown) {
            return dp[i][iscooldown][holding] =
                solve(prices,i+1,n,false,holding);
        }

        int ans = solve(prices,i+1,n,false,holding); // skip

        if(!holding) {
            // buy
            ans = max(ans,
                -prices[i] + solve(prices,i+1,n,false,true));
        }
        else {
            // sell
            ans = max(ans,
                prices[i] + solve(prices,i+1,n,true,false));
        }

        return dp[i][iscooldown][holding] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
for(int i = 0; i < 5001; i++) {
    for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
            dp[i][j][k] = -1;
        }
    }
}
        return solve(prices,0,n,false,false);
    }
};