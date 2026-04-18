class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int curr = 0;
        for(auto i:nums) {
            curr+=i;
            max_sum = max(max_sum,curr);
            if(curr<0) curr = 0;
        }
        return max_sum;
    }
};
