class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> qs;
        int qsize = queries.size();
        vector<int> ans(qsize, -1);

        for (int i = 0; i < qsize; i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minH;
        int i = 0;
        for (auto q : qs) {
            while (i < n && intervals[i][0] <= q.first) {
                minH.push({intervals[i][1] - intervals[i][0] + 1, i});
                i++;
            }

            // remove all of the intervals which are passed
            while (!minH.empty()) {
                int idx = minH.top().second;
                if (intervals[idx][1] < q.first) {
                    minH.pop();
                } else {
                    break;
                }
            }

            if (minH.empty()) {
                ans[q.second] = -1;
            } else {
                ans[q.second] = minH.top().first;
            }
        }

        return ans;
    }
};