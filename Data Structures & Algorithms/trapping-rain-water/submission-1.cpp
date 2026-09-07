#define sz(a) (int)(a).size()
class Solution {
public:
    int trap(vector<int>& height) {
        // For any given x value, the amount of water that can be trapped is dependent on
        // min(tallest bar on the left, tallest bar on the right) -> construct prefix and suffix arrays
        int n = sz(height);
        vector<int> pre(n), suf(n);
        pre[0] = height[0];
        suf[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            pre[i] = max(pre[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = max(suf[i + 1], height[i]);
        }

        int total = 0;
        for (int i = 1; i < n - 1; ++i) {
            total += max(0, min(pre[i], suf[i]) - height[i]);
        }
        return total;
    }
};
