class Solution {
public:
    bool solve(vector<int>& nums,int n, int targetSum) {
        if(n==0) {
            return targetSum==0;
        }
        if(nums[n-1]<=targetSum && solve(nums,n-1,targetSum-nums[n-1])) return true;
        return solve(nums,n-1,targetSum);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums) {
            sum+=i;
        }
        if(sum%2) return false;
        int targetSum = sum/2;
        int n = nums.size();
        return solve(nums,n,targetSum);
    }
};
