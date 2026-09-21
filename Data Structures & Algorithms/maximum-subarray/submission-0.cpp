#define sz(a) (int)(a).size()

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm
        int best = nums[0], cur = 0;
        for (auto e : nums) {
            cur += e;
            best = max(best, cur);
            cur = max(cur, 0);
        }
        return best;
    }
};
