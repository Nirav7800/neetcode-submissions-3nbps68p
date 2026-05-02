class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;
        int r = 1;
        for(int i=n-1;i>=0;i--) {
            ans.push_back((digits[i]+r)%10);
            r = (digits[i]+r)/10;
        }

        if(r) ans.push_back(r);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
