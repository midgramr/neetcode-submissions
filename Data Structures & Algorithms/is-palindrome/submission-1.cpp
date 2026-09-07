#define sz(a) (int)(a).size()

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;
        for (auto &c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        int n = sz(cleaned);
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (cleaned[i] != cleaned[j]) return false;
        }
        return true;
    }
};
