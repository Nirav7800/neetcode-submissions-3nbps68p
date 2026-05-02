class Solution {
public:
    int jump(vector<int>& nums) {
        int max_range = nums[0];
        int jump=1;
        int idx =0;
        int n = nums.size();
        if(n==1) return 0;
        while(max_range<n-1) {
            int nextrange = 0;
            int nextidx = idx+1;
            jump++;
            for(int i=idx+1;i<=max_range;i++) {
                if(i+nums[i]>nextrange) {
                 nextrange = i+nums[i];
                 nextidx = i;
                }
                
            }
            max_range = nextrange;
            idx=nextidx;
        }
        return jump;
    }
};
