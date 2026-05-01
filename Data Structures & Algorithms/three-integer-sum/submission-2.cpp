class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<n-2;i++) {
            if(i && nums[i]==nums[i-1]) continue;
            int p1 = i+1;
            int p2 = n-1;
            
            while(p1<p2) {
            int sum = nums[i]+nums[p1]+nums[p2];
            if(sum==0) {
                ans.push_back({nums[i],nums[p1],nums[p2]});
                p1++;
                p2--;
                while(p1<p2 && nums[p1]==nums[p1-1])
                p1++;
                while(p2>p1 && nums[p2]==nums[p2+1])
                p2--;
            } else if(sum>0) {
                p2--;
            } else {
                p1++;
            }
            }
            
        }
        return ans;
    }
};
