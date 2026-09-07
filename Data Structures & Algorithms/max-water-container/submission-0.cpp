#define sz(a) (int)(a).size()
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int best = 0;
        for (int i = 0, j = sz(heights) - 1; i < j;) {
            int cur = (j - i) * min(heights[i], heights[j]);
            best = max(cur, best);
            if (heights[i] <= heights[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return best;
    }
};
