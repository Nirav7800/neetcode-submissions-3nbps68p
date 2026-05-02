class Solution {
public:
    bool isHappy(int n) {
        long long sum = n;
        unordered_set<long long>s;
        while(true) {
            long long curr = 0;
            while(sum) {
                int d = sum%10;
                curr = curr+d*d;
                sum/=10;
            }
            if(curr==1) return true;
            if(s.find(curr)!=s.end()) {
                return false;
            }
            s.insert(curr);
            sum = curr;
        }
        return true;
    }
};
