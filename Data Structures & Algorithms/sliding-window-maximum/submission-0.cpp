class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        int p1 =0;
        while(p1<k) {
            while(!q.empty() && q.back()<nums[p1]) q.pop_back();
            q.push_back(nums[p1]);
            p1++;
        }
        vector<int>ans;
        int n = nums.size();
        while(p1<n){
            ans.push_back(q.front());
            if(nums[p1-k]==q.front()) q.pop_front();

            while(!q.empty() && q.back()<nums[p1]) q.pop_back();
                        
            q.push_back(nums[p1]);
            p1++;
        }
        ans.push_back(q.front());
        return ans;
    }
};
