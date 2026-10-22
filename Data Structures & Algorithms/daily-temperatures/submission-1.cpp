#define sz(a) (int)(a).size();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Monotonically non-increasing stack? 
        // Push indices onto the stack, since can use temperatures to get the actual temperature
        int n = sz(temperatures);
        
        stack<int> stk;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int t = temperatures[i];
            while (!stk.empty() && temperatures[stk.top()] < t) {
                int j = stk.top();
                ans[j] = i - j;
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};
