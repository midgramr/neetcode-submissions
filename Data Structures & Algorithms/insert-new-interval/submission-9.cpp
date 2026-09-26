class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool added = false;
        int start = newInterval[0], end = newInterval[1];
        for (auto &in : intervals) {
            if (in[1] < start) {
                ans.push_back(in);
            } else if (in[0] > end) {
                if (!added) {
                    ans.push_back({start, end});
                    added = true;
                }
                ans.push_back(in);
            } else {
                start = min(start, in[0]);
                end = max(end, in[1]);
            }
        }
        if (!added) ans.push_back({start, end});
        return ans;
    }
};
