#define sz(a) (int)(a).size()

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // For every block, find the closest block on either side that has height < it, that's the non-inclusive boundary for the largest rectangle that can be formed using the height of that block
        int n = sz(heights);
        vector<int> left(n, -1), right(n, n);

        stack<pair<int, int>> stk;
        for (int i = 0; i < n; ++i) {
            int e = heights[i];
            while (!stk.empty() && stk.top().first >= e) {
                stk.pop(); }
            if (!stk.empty()) {
                left[i] = stk.top().second;
            }
            stk.push({e, i});
        }

        stk = stack<pair<int, int>>();
        for (int i = n - 1; i >= 0; --i) {
            int e = heights[i];
            while (!stk.empty() && stk.top().first >= e) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top().second;
            }
            stk.push({e, i});
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};
