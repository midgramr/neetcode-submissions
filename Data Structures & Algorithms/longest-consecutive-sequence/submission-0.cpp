#define sz(a) (int)(a).size()

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int ans = 1, cur = 1;
        for (int i = 1; i < sz(nums); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                cur += 1;
            } else if (nums[i] == nums[i - 1]) {
                continue;
            } else {
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};
