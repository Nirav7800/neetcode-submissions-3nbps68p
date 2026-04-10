class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans = 0;
        for(auto i:nums) {
            st.insert(i);
        }

        for(auto i:nums) {
            if(st.find(i-1)!=st.end()) {
                continue;
            }
            int curr = 1;
            int ele = i;
            while(st.find(ele+1)!=st.end()) {
                curr++;
                ele = ele+1;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};
