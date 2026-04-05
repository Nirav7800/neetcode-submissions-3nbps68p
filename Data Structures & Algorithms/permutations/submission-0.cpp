class Solution {
public:
    void generate(vector<int>& nums,vector<int>curr, vector<vector<int>>&ans,
    vector<int>vis) {
        if(curr.size()==nums.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!vis[i]) {
                curr.push_back(nums[i]);
                vis[i]=1;
                generate(nums,curr,ans,vis);
                vis[i]=0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        vector<vector<int>>ans;
        vector<int>vis(n,0);
        generate(nums,curr,ans,vis);
        return ans;
    }
};
