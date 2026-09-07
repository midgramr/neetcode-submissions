class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, lo = prices[0];
        for (auto &e : prices) {
            ans = max(ans, e - lo);
            lo = min(lo, e);
        }
        return ans;
    }
};
