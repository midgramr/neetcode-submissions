class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Intuition: sort the intervals by start time and keep track of the end of the current window; if the start time of an interval comes after the end of the current window, create a new window. Must sort by start time since that's what guarantees that all future intervals will come after a finalized window
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        for (auto &in : intervals) {
            if (in[0] <= end) {
                end = max(in[1], end);
            } else {
                ans.push_back({start, end});
                start = in[0], end = in[1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
