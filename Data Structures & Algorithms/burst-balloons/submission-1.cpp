class Solution {
public:
    int dp[301][301];
    int solve(vector<int>& nums,int l,int r, int n) {
       if(l==r) {
    int ans = nums[l];
    if(l!=0) ans *= nums[l-1];
    if(r!=n-1) ans *= nums[r+1];
    return ans;
}
        if(l>r)  return 0;
        int max_ans = 0;
        if(dp[l][r]!=-1) return dp[l][r];
        for(int i=l;i<=r;i++) {
            int ans =nums[i];
            if(l!=0) {
               ans*=(nums[l-1]);
            }
            if(r!=n-1) {
               ans*=(nums[r+1]);
            }
            ans+=(solve(nums,l,i-1,n)+solve(nums,i+1,r,n));
            max_ans=max(max_ans,ans);
        }
        
        return dp[l][r]=max_ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=300;i++){
            for(int j=0;j<=300;j++) {
                dp[i][j]=-1;
            }
        }
        return solve(nums,0,n-1,n);
    }
};
