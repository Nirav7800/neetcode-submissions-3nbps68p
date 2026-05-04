class Solution {
public:
    int solve(vector<int>&coins, int n,int amount){
        if(amount==0) {
            return 0;
        }

        if(n==0) {
            return INT_MAX-1;
        }

        //take
        int total=INT_MAX-1;
        if(coins[n-1]<=amount) {
             total=1+solve(coins,n,amount-coins[n-1]);
        }
        //skip
        total=min(total,solve(coins,n-1,amount));
        return total;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int coinsneeded = solve(coins,n,amount);
        return coinsneeded==INT_MAX-1?-1:coinsneeded;
    }
};
