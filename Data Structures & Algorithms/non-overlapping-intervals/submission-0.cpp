bool comp(vector<int>a,vector<int>b) {
    return a[1]<b[1]||(a[1]==b[1] && a[0]<b[0]);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int count =0;
        vector<int>prev = intervals[0];
        for(int i=1;i<n;i++) {
            if(intervals[i][0]>=prev[1]) {
                prev=intervals[i];
            } else {
                count++;
            }
        }
        return count;
    }
};
