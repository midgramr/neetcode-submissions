#define sz(a) (int)(a).size()

class Solution {
public:
    int characterReplacement(string s, int k) {
        // Idea: find a substring with the fewest number of distinct characters, however this doesn't take length into account since a substring of length 1 trivially has 1 distinct character
        // Idea: slide a window over s. Move the left pointer when window size - most common character count > k
        if (s.empty()) return 0;
        vector<int> cnt(26);
        int ans = 0;
        for (int i = 0, j = 0; j < sz(s); ++j) {
            cnt[s[j] - 'A']++;
            // Implicitly ensures i <= j
            while ((j - i + 1) - *max_element(cnt.begin(), cnt.end()) > k) {
                cnt[s[i] - 'A']--;
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
