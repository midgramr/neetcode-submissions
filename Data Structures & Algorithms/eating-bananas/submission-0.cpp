class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        // Search for the first value of k that works
        while (l < r) {
            int k = l + (r - l) / 2;
            // Verify that the current k works
            int total = 0;
            for (auto &e : piles) {
                total += e / k + (e % k != 0);
            }
            if (total > h) {
                l = k + 1;
            } else {
                r = k;
            }
        }
        return l;
    }
};
