#define sz(a) (int)(a).size()
using ll = long long;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = sz(nums1), m = sz(nums2);
        if (n > m) return findMedianSortedArrays(nums2, nums1);
        int total = n + m;
        int target = (total + 1) / 2;
        int l = 0, r = n;
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = target - i;

            int al = i > 0 ? nums1[i - 1] : INT_MIN;
            int ar = i < n ? nums1[i] : INT_MAX;
            int bl = j > 0 ? nums2[j - 1] : INT_MIN;
            int br = j < m ? nums2[j] : INT_MAX;

            if (al <= br && bl <= ar) {
                if (total % 2 == 0) {
                    return (max(al, bl) + min(ar, br)) / 2.0;
                } else {
                    return max(al, bl);
                }
            } else if (al > br) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};
