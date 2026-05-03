class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 1;
        int hi = n-1;
        if(nums[0]==target) return 0;
        if(nums[n-1]==target) return n-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target) {
                return mid;
            }
            //check target is in first half or second
            if(nums[0]<=target) {
                //now check where is mid;
                //mid is in second part
                if(nums[mid]<nums[0]) {
                    hi = mid-1;
                } else {
                    if(nums[mid]>target) {
                        hi = mid-1;
                    } else {
                        lo = mid+1;
                    }
                }

            } else {
                if(nums[mid]>nums[0]) {
                    lo = mid+1;
                } else {
                    if(nums[mid]>target) {
                        hi = mid-1;
                    } else {
                        lo = mid+1;
                    }
                }

            }
        }
        return -1;
    }
};
