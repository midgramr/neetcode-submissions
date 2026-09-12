#define sz(a) (int)(a).size()
using ll = long long;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = sz(nums1), m = sz(nums2);
        int target = (n + m + 1) / 2;
        for (int k = 0; k < target; ++k) {
            if (i >= n) {
                ++j;
            } else if (j >= m) {
                ++i;
            } else {
                nums1[i] <= nums2[j] ? ++i : ++j;
            }
        }
        ll al = i > 0 ? nums1[i - 1] : INT_MIN;
        ll ar = i < n ? nums1[i] : INT_MAX;
        ll bl = j > 0 ? nums2[j - 1] : INT_MIN;
        ll br = j < m ? nums2[j] : INT_MAX;
        if ((n + m) % 2 == 0) {
            return (max(al, bl) + min(ar, br)) / 2.0;
        } else {
            return max(al, bl);
        }
    }
};
