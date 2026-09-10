#define sz(a) (int)(a).size()

class Solution {
public:
    int findMin(vector<int> &nums) {
        // Given a range [l, r], compare the ends with the midpoint m
        // If l <= m, then the pivot is to the right of m
        // conversely, if l > m, then the pivot is to the left, inclusive of m
        // Basically we're searching for the first index where nums[i] < nums[i - 1]
        // Edge case: l == r - 1
        int l = 0, r = sz(nums) - 1;
        // We've established that the first element cannot be the pivot
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[l] < nums[r]) return nums[l];
            if (l == r - 1) return min(nums[l], nums[r]);
            if (nums[m] > nums[l]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
