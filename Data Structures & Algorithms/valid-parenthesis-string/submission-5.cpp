class Solution {
public:
    bool checkValidString(string s) {
        // Track the smallest and largest possible number of unmatched open brackets
        int lo = 0, hi = 0;
        for (auto chr : s) {
            if (chr == '(') {
                ++lo; ++hi;
            } else if (chr == ')') {
                --lo; --hi;
            } else {
                --lo;
                ++hi;
            }
            lo = max(lo, 0);
            if (hi < 0) return false;
        }
        return lo == 0;
    }
};
