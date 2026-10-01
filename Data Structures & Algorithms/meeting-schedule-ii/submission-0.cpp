class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        for (auto& interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0, maxRooms = 0, i = 0, j = 0;
        while (i < start.size()) {
            if (start[i] < end[j]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                rooms--;
                j++;
            }
        }
        return maxRooms;
    }
};
