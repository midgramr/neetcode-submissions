#define sz(a) (int)(a).size()

class Solution {
public:
    int jump(vector<int>& nums) {
        // Another BFS approach, but use a left/right pointer to track the current indices under consideration; when every index from left -> right has been explored, we add another jump to our paths under consideration
        int n = sz(nums);
        int l = 0, r = 0, d = 0;
        while (r < n - 1) {
            // There is guaranteed to exist a path to the end, so we can assume that the next window starts after the end of the current one
            int nl = r + 1, nr = r + 1;
            for (int i = 0; i <= r; ++i) {
                nr = max(nr, min(n - 1, i + nums[i]));
            }
            ++d;
            l = nl;
            r = nr;
        }
        return d;
    }
};
