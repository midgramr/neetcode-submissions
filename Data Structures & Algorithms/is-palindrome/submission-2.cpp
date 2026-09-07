#define sz(a) (int)(a).size()

class Solution {
public:
    bool isPalindrome(string s) {
        int n = sz(s);
        for (int i = 0, j = n - 1; i < j;) {
            if (!isalnum(s[i])) {
                ++i;
                continue;
            }
            if (!isalnum(s[j])) {
                --j;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i, --j;
        }
        return true;
    }
};
