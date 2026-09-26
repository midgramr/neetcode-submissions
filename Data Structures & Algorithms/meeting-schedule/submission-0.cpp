#define sz(a) (int)(a).size()

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Just need to check if there are any overlapping intervals
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            if (a.start != b.start) return a.start < b.start;
            return a.end < b.end;
        });
        int end = intervals[0].end;
        for (int i = 1; i < sz(intervals); ++i) {
            auto in = intervals[i];
            if (in.start < end) {
                return false;
            } else {
                end = in.end;
            }
        }
        return true;
    }
};
