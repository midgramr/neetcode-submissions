#define sz(a) (int)(a).size()

class Solution {
public:
    string minWindow(string s, string t) {
        // Idea: keep enlarging the current window until every character in t is present, then start shrinking until not every character from t is present. Record the lengths
        int n = sz(s), m = sz(t);
        if (m > n) return "";

        unordered_map<char, int> target, cur;
        int matched = 0;
        for (auto &c : t) {
            target[c]++;
        }

        bool found = false;
        int l, r;
        for (int i = 0, j = 0; j < n; ++j) {
            if (!target.count(s[j])) {
                continue;
            }
            cur[s[j]]++;
            if (cur[s[j]] == target[s[j]]) {
                matched++;
                if (matched == sz(target)) {
                    if (!found) {
                        l = i, r = j;
                        found = true;
                    }
                    while (matched == sz(target)) {
                        if (j - i < r - l) {
                            l = i, r = j;
                        }
                        if (cur.count(s[i])) {
                            if (cur[s[i]] == target[s[i]]) {
                                matched--;
                            }
                            cur[s[i]]--;
                        }
                        ++i;
                    }
                }
            }
        }
        if (!found) return "";
        return s.substr(l, r - l + 1);
    }
};
