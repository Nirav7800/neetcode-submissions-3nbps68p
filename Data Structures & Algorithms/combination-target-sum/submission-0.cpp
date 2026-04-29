class Solution {
public:
    void solve(vector<int>& nums,int i, int target,int n, vector<int>curr, vector<vector<int>>&ans) {
        if(i==n) {
            if(target==0) ans.push_back(curr);
            return;
        }
        if((i==0 ||  nums[i]!=nums[i-1]) && nums[i]<=target) {
            curr.push_back(nums[i]);
            solve(nums,i,target-nums[i],n,curr,ans);
            curr.pop_back();
        }
        solve(nums,i+1,target,n,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,target,nums.size(),curr,ans);
        return ans;
    }
};
