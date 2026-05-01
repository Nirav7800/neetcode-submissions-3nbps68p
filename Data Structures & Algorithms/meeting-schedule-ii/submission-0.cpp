/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int max_time = 0;
        for(int i=0;i<n;i++){
            max_time=max(max_time,intervals[i].end);
        }
        vector<int>rooms(max_time+1,0);
        for(auto i:intervals) {
            int s = i.start;
            int e = i.end;
            rooms[s]++;
            rooms[e]--;
        }
        int count = rooms[0];
        for(int i=1;i<=max_time;i++) {
            rooms[i]+=rooms[i-1];
            count = max(count,rooms[i]);
        }
        return count;
    }
};
