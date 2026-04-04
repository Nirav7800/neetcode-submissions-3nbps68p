class Solution {
public:
   void solve(vector<int>&candidates, int i ,int n, int target, vector<int>curr,vector<vector<int>>&ans) {
      if(target==0) {
        ans.push_back(curr);
        return;
      }
      if(i==n) return;
      if(target>=candidates[i]) {
         curr.push_back(candidates[i]);
         solve(candidates,i+1,n,target - candidates[i],curr,ans);
         curr.pop_back();
      }

      while(i<n-1 && candidates[i]==candidates[i+1]) i++;
      solve(candidates,i+1,n,target,curr,ans);
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        solve(candidates,0,n,target,curr,ans);
        return ans;

    }
};