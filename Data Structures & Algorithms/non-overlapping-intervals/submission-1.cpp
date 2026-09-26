#define sz(a) (int)(a).size()

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // An interval can only overlap another if one's start < the other's end
        // If we sort by start time, we can tell which intervals overlap, but not necessarily the minimum number to remove
        // If multiple intervals share the same start, then all but one must be removed; idea: keep only the one with the earliest end time

        // Idea: start by end times; remove any interval that overlaps with the current end time. When a new interval is found that doesn't overlap, set that interval's end as the new end time and repeat
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[1] != b[1]) return a[1] < b[1];
            else return a[0] < b[0];
        });
        int ans = 0, end = intervals[0][1];
        for (int i = 1; i < sz(intervals); ++i) {
            auto in = intervals[i];
            if (in[0] < end) {
                ++ans;
            } else {
                end = in[1];
            }
        }
        return ans;
    }
};
