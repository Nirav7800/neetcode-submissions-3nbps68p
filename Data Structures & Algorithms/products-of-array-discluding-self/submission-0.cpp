class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int no_of_zeros = 0;
        int n = nums.size();
        for(auto i:nums) {
            if(i==0) {
                no_of_zeros++;
            }
        }
        vector<int>ans;
        if(no_of_zeros>=2) {
            for(auto i:nums) {
                ans.push_back(0);
            }
            return ans;
        }
        if(no_of_zeros) {
            int mul = 1;
            for(auto i:nums) {
                if(i!=0) {
                    mul*=i;
                }
            }
            for(auto i:nums) {
                if(i==0) {
                    ans.push_back(mul);
                }else {
                    ans.push_back(0);
                }
            }

            return ans;
        }
        int mul = 1;

        for(auto i:nums) {
            ans.push_back(mul);
            mul*=i;
        }

        mul = 1;
        for(int i=n-1;i>=0;i--) {
            ans[i]*=mul;
            mul*=nums[i];
        }
        return ans;
    }
};
