#define sz(a) (int)(a).size()

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        int n = sz(speed);
        for (int i = 0; i < n; ++i) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end());
        stack<double> stk;
        for (int i = n - 1; i >= 0; --i) {
            double time = (double)(target - pairs[i].first) / pairs[i].second;
            if (stk.empty() || time > stk.top()) {
                stk.push(time);
            }
        }
        return sz(stk);
    }
};
