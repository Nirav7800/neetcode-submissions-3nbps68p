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
bool comp(Interval a,Interval b) {
    return a.start<b.start || (a.start==b.start && a.end<b.end); 
}
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        Interval curr = intervals[0];
        for(int i=1;i<n;i++) {
            if(curr.end>intervals[i].start) {
                return false;
            }
            curr = intervals[i];
        }
        return true;
    }
};
