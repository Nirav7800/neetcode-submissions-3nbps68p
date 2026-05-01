class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        for(int i=0;i<n;i++) {
            if(intervals[i][1]<newIntervals[0]) {
                ans.push_back(intervals[i]);
            } else if(intervals[i][0]>newIntervals[1]) {
                ans.push_back(newIntervals);
                while(i<n) {
                    ans.push_back(intervals[i++]);
                }
                return ans;
            } else {
                newIntervals[0]=min( newIntervals[0],intervals[i][0]);
                newIntervals[1]=max(newIntervals[1],intervals[i][1]);
            }
        }
        ans.push_back(newIntervals);
        return ans;
    }
};
