#define sz(a) (int)(a).size()

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Idea: sort by (end time, start time), iterate and track the end of the current interval. If the next interval intersects with the current end, merge, otherwise start a new interval

        // Stores the first possible place newInterval could be inserted
        // Edge case: newInterval would be the first interval
        if (intervals.empty() || newInterval[0] < intervals.front()[0]) {
            intervals.insert(intervals.begin(), newInterval);
        } else {
            int i;
            for (i = 0; i < sz(intervals); ++i) {
                if (newInterval[0] >= intervals[i][0]) {
                    break;
                }
            }
    
            // Find the last possible place newInterval could be inserted
            for (; i < sz(intervals); ++i) {
                if (intervals[i][0] > newInterval[0]) break;
            }
    
            intervals.insert(intervals.begin() + i, newInterval);
        }

        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < sz(intervals); ++i) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};
