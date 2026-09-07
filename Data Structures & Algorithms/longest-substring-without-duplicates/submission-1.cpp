#define sz(a) (int)a.size()

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_set<char> seen;
        int ans = 0;
        for (int i = 0, j = 0; j < sz(s); ++j) {
            while (seen.count(s[j])) {
                seen.erase(s[i]);
                ++i;
            }
            seen.insert(s[j]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
