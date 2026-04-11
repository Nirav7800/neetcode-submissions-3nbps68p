class Solution {
public:
    int solve(vector<int>& nums, int target,int i, int n) {
        if(i==n) {
            return target==0;
        }
        int ans = 0;
        if(nums[i]<=target){
            ans+=solve(nums,target-nums[i],i+1,n);
        }
        ans+=solve(nums,target,i+1,n);
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
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
