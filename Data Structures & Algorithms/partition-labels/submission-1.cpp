#define sz(a) (int)(a).size()

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Characters can be "interleaved", thus you cannot create windows simply based on the first and last appearances of a character
        // x: 0, 3 <- The window that includes x must be extended to include the last occurrence of every character that appears between 0 and 3; for each of those letters, that recursively applies
        // y: 1, 4

        // e.g., xyaxybazzb

        // Idea: precompute the first and last index of each letter. Then maintain a list of characters that must be included in the current window. Remove a character from the window when we encounter its last index. Add a character to the window if we haven't encountered it yet. If we no longer have any characters in the window, then we create a new window, which represents a new substring in the output

        vector<int> first(26, INT_MAX), last(26, INT_MIN);
        for (int i = 0; i < sz(s); ++i) {
            int c = s[i] - 'a';
            first[c] = min(i, first[c]);
            last[c] = max(i, last[c]);
        }

        vector<int> ans;
        // cur = size of window, chrs = unique chars in window
        int cur = 0, chrs = 0;
        for (int i = 0; i < sz(s); ++i) {
            int c = s[i] - 'a';
            ++cur;
            if (i == first[c]) {
                ++chrs;
            }
            if (i == last[c]) {
                --chrs;
                if (chrs == 0) {
                    ans.push_back(cur);
                    cur = 0;
                }
            }
        }
        if (cur > 0) {
            ans.push_back(cur);
        }
        return ans;
    }
};
