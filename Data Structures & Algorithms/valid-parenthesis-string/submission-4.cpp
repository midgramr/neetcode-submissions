#define sz(a) (int)(a).size()

class Solution {
public:
    bool checkValidString(string s) {
        // Stack-based approach
        stack<int> open, star;
        int n = sz(s);
        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
            case '(':
                open.push(i);
                break;
            case '*':
                star.push(i);
                break;
            default:
                if (!open.empty()) {
                    open.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }
        while (!star.empty() && !open.empty()) {
            if (open.top() > star.top()) return false;
            open.pop(); star.pop();
        }
        return open.empty();
    }
};
