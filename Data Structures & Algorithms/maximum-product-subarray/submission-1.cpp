class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
       int ans = nums[0];
       int min_prod = nums[0];
       int max_prod = nums[0];
       for(int i=1;i<n;i++){
         if(nums[i]==0) {
            min_prod = 0;
            max_prod = 0;
            ans = max(ans,0);
            continue;
         } 
         int temp = min_prod;
         min_prod = min(min_prod*nums[i],min(nums[i],max_prod*nums[i]));
         max_prod = max(max_prod*nums[i],max(nums[i],temp*nums[i]));
         ans = max(max_prod,ans);
       }
       return ans;
    }
};
