class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto &c : s) {
            if (c == ')' || c == '}' || c == ']') {
                if (stk.empty()) return false;
                if (c == ')' && stk.top() != '(') return false;
                if (c == '}' && stk.top() != '{') return false;
                if (c == ']' && stk.top() != '[') return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
