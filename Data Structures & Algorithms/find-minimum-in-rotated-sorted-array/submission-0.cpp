class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        //array is not rottated
        if(nums[0]<=nums[n-1]) return nums[0];
        //array is reverssed
        if(nums[n-1]<=nums[n-2]) return nums[n-1];

        int lo = 1;
        int hi = n-2;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                return nums[mid];
            }
            //mid in first half
            if(nums[mid]>nums[0]) {
                lo = mid+1;
            }

            //mid is in second half;
            if(nums[mid]<nums[0] && nums[mid]>=nums[mid-1]) {
                hi = mid-1;
            }
        }
        return nums[lo];
    }
};
