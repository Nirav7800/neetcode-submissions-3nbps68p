class Solution {
public:
    void subsetwithduphelper(vector<int>& nums,int start,vector<int>currset,vector<vector<int>>& ans,int c)
    {
        if(currset.size()==c) {
            ans.push_back(currset);
            return ;
        }
            
            for(int i=start;i<nums.size();i++)
            {
                if(i!=start && nums[i]==nums[i-1]) continue;
                currset.push_back(nums[i]);
                subsetwithduphelper(nums,i+1,currset,ans,c);
                currset.pop_back();
            }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>currset;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++)
            subsetwithduphelper(nums,0,currset,ans,i);
        return ans;
    }
};