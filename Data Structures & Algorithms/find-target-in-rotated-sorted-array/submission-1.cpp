#define sz(a) (int)(a).size()

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = sz(nums) - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int pivot = l;
        if (target <= nums.back()) {
            l = pivot, r = sz(nums) - 1;
        } else {
            l = 0, r = pivot - 1;
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};
