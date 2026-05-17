class Solution {
private: 
    void backtrack(vector<int>& nums,int i,int n, vector<int>&curr,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        //include
        curr.push_back(nums[i]);
        backtrack(nums,i+1,n,curr,ans);
        curr.pop_back();
        //skipp all occurance
        while(i+1<n && nums[i]==nums[i+1]) i++;
        backtrack(nums,i+1,n,curr,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,nums.size(),curr,ans);
        return ans;
    }
};
