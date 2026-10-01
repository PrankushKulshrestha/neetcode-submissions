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
    static bool mycmp(Interval& a, Interval& b){
        if(a.start == b.start)
            return a.end <= b.end;
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int index = 0;
        int size = intervals.size();
        sort(intervals.begin(),intervals.end(),mycmp);
        for(int i=1;i<size;i++){
            if(intervals[index].end <= intervals[i].start)
                index++;
            else{
                return false;
                // intervals[index][0] = min(intervals[index][0],intervals[i][0]);
                // intervals[index][1] = max(intervals[index][1],intervals[i][1]);
            }
        }
        // intervals.resize(index+1);
        return true;
    }
};
