class Solution {
public:
    int dp[21][1001];
    int solve(vector<int>& nums, int target,int i, int n) {
        if(i==n) {
            return target==0;
        }
        int ans = 0;
        if(dp[i][target]!=-1) return dp[i][target]; 
        if(nums[i]<=target){
            ans+=solve(nums,target-nums[i],i+1,n);
        }
        ans+=solve(nums,target,i+1,n);
        return dp[i][target]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        for(int i=0;i<=20;i++) {
            for(int j=0;j<=1000;j++) {
                dp[i][j]=-1;
            }
        }
        int sum = 0;
        for(auto i:nums) {
            sum+=i;
        }
        int rsum = (sum+target)/2;
        if((sum+target)%2) {
            return 0;
        }
        return solve(nums,rsum,0,nums.size());
    }
};
