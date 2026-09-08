#define sz(a) (int)(a).size();
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Intuition tells me this is a monotonic stack problem
        // want to maintain a stack of numbers to the right in decreasing order along with their indicies
        // whenever we encounter a situation where nums[i] >= the top of the stack, we keep popping
        // until either the stack is empty or nums[i] < top
        // the reason we can pop smaller numbers from the stack is because earlier nums only care what
        // numbers to the right of themselves are greater, so anything to the right <= nums[i] becomes
        // irrelevant
        stack<pair<int, int>> stk;
        int n = sz(temperatures);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int e = temperatures[i];
            while (!stk.empty() && stk.top().first <= e) {
                stk.pop();
            }
            if (stk.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = stk.top().second - i;
            }
            stk.push({e, i});
        }
        return ans;
    }
};
