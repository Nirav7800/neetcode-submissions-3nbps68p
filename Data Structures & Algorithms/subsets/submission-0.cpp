class Solution {
public:
    void solve(vector<int>&nums,int i,int n,vector<int>curr, vector<vector<int>>&ans) {
        if(i==n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(nums,i+1,n,curr,ans);
        curr.pop_back();
        solve(nums,i+1,n,curr,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        solve(nums,0,n,curr,ans);
        return ans;
    }
};
