class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto &s : tokens) {
            char c = s[s.size() - 1];
            if (isalnum(c)) {
                stk.push(stoi(s));
            } else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                switch (c) {
                    case '+':
                        stk.push(a + b);
                        break;
                    case '-':
                        stk.push(a - b);
                        break;
                    case '*':
                        stk.push(a * b);
                        break;
                    case '/':
                        stk.push(a / b);
                        break;
                }
            }
        }
        return stk.top();
    }
};
