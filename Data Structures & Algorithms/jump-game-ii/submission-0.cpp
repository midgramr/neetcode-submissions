#define sz(a) (int)(a).size()

class Solution {
public:
    int jump(vector<int>& nums) {
        // BFS intuition: for each number of jumps, you unlock a (potentially 0) number of new tiles; split the array into sections by number of jumps required to reach. The first time you reach the last tile will be the smallest number of jumps required
        queue<int> q;
        vector<int> seen(sz(nums));
        seen[0] = true;
        q.push(0);
        int d = 0;
        while (!q.empty()) {
            int size = sz(q);
            for (int k = 0; k < size; ++k) {
                int i = q.front(); q.pop();
                if (i == sz(nums) - 1) return d;
                for (int j = i + 1; j <= min(sz(nums) - 1, i + nums[i]); ++j) {
                    if (!seen[j]) {
                        seen[j] = true;
                        q.push(j);
                    }
                }
            }
            ++d;
        }
        return d - 1;
    }
};
