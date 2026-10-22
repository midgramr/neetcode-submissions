#define sz(a) (int)(a).size()

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Find the longest window where most frequent character count + k = window size
        // Idea: sliding window; increase window size when most frequent chr count + k >= window size, decrease window size while that's not true
        vector<int> cnt(26);
        int ans = 1;
        for (int i = 0, j = 0; j < sz(s); ++j) {
            int c = s[j] - 'A';
            cnt[c]++;

            while (*max_element(cnt.begin(), cnt.end()) + k < j - i + 1) {
                cnt[s[i] - 'A']--;
                ++i;
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
