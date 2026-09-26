#define sz(a) (int)(a).size()

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Idea: sort by (end time, start time), iterate and track the end of the current interval. If the next interval intersects with the current end, merge, otherwise start a new interval
        vector<vector<int>> sorted{intervals};
        sorted.push_back(newInterval);
        sort(sorted.begin(), sorted.end());

        vector<vector<int>> ans;
        int start = sorted[0][0], end = sorted[0][1];
        for (int i = 1; i < sz(sorted); ++i) {
            if (sorted[i][0] <= end) {
                end = max(end, sorted[i][1]);
            } else {
                ans.push_back({start, end});
                start = sorted[i][0];
                end = sorted[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};
