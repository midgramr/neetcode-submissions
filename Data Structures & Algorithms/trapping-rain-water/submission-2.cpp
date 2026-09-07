#define sz(a) (int)(a).size()

class Solution {
public:
    int trap(vector<int>& height) {
        // Same idea as before: for any given x value, the water to be trapped is dependent
        // on min(tallest on the left, tallest on the right)
        // However, it's possible to compute this in one pass with 2 pointers without supplemental DS
        // Start with 2 pointers on either end.
        // - for the left pointer, I will always know the tallest on the left, likewise for the right
        // pointer I will always know the tallest on the right
        // For my left pointer, if the tallest on the left is taller than the tallest on the right (discovered so far), then it makes sense to increment the right side and not yet count the water for the left pointer, since we could still discover a taller pillar on the right. Likewise for the right pointer

        int n = sz(height);
        int total = 0, hl = height[0], hr = height[n - 1];
        for (int i = 1, j = n - 2; i <= j;) {
            if (hl <= hr) {
                total += max(0, min(hl, hr) - height[i]);
                hl = max(hl, height[i]);
                ++i;
            } else {
                total += max(0, min(hl, hr) - height[j]);
                hr = max(hr, height[j]);
                --j;
            }
        }
        return total;
    }
};
