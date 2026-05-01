class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++) {
           int ele = nums[i];
           int pos = lower_bound(lis.begin(),lis.end(),ele)-lis.begin();
           if(pos==lis.size()) {
            lis.push_back(nums[i]);
           } else {
            lis[pos]=ele;
           }
        }
        return lis.size();
    }
};
