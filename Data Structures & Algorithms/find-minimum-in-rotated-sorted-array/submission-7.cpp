#define sz(a) (int)(a).size()

class Solution {
public:
    int findMin(vector<int> &nums) {
        // Binary search the pivot point
        // Numbers are unique -> don't worry about duplicates
        // if nums[l] > nums[r] -> the pivot point is somewhere between l and r
        // if nums[m] > nums[l] -> the pivot point is to the right of m
        // if nums[m] < nums[r] -> the pivot point is between l and m, inclusive of m
        // if nums[m] > nums[r] -> pivot point to the right of m
        // Edge case: l = r - 1 -> m = l

        int l = 0, r = sz(nums) - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
