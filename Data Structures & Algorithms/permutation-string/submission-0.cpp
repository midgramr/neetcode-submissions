#define sz(a) (int)(a).size()

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = sz(s1), m = sz(s2);
        if (n > m) return false;
        
        // Even if I track character occurrences in each window, verifying that my current window equals s1 is costly (O(n)). Rather, I should have a variable that stores the number of characters satisfied in the current window so the final "equals" check can be done in O(1)
        unordered_map<char, int> target, cur;
        int matched = 0;
        for (auto &c : s1) {
            target[c]++;
        }

        for (int i = 0, j = 0; j < m; ++j) {
            if (!target.count(s2[j])) {
                // Current window cannot possibly be valid
                cur.clear();
                matched = 0;
                i = j + 1;
            } else {
                char c = s2[j];
                cur[c]++;
                if (cur[c] == target[c]) {
                    matched++;
                    if (matched == sz(target)) {
                        return true;
                    }
                } else if (cur[c] > target[c]) {
                    while (cur[c] > target[c]) {
                        if (cur[s2[i]] == target[s2[i]]) {
                            matched--;
                        }
                        cur[s2[i]]--;
                        ++i;
                    }
                }
            }
        }

        return false;
    }
};
