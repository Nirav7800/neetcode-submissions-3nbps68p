class Solution {
public:
    bool possible(vector<int>& piles,int rate, int h){
        long long rh =0;
        for(auto i:piles) {
            rh+= ceil((1.0*i)/rate);
        }
        return h>=rh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1;
        int hi = piles[0];
        for(auto p:piles) {
            lo=min(p,lo);
            hi=max(p,hi);
        }
        int ans = hi;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(possible(piles,mid,h)) {
                ans=mid;
                hi=mid-1;
            } else {
                lo=mid+1;
            }
        }
        return ans;
    }
};
