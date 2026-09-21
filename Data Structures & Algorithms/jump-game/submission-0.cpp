#define sz(a) (int)(a).size()

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Use a variable to track the farthest tile I can jump to; iteratively update and check whether this farthest tile includes the last index
        int k = 0;
        for (int i = 0; i < sz(nums); ++i) {
            if (k < i) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
