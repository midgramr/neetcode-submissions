class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Store unique numbers in a set
        // On second pass, only start checking a sequence length if num - 1 is not in the set,
        // i.e., the current number is the start of a sequence
        // This way of iterating ensures a number if looked at at most twice when counting both passes
        unordered_set<int> seen;
        for (auto e : nums) {
            seen.insert(e);
        }

        int ans = 0;
        for (auto e : nums) {
            if (seen.count(e - 1)) continue;
            int cur = e, len = 0;
            while (seen.count(cur)) {
                ++cur;
                ++len;
            }
            ans = max(ans, len);
        }
        
        return ans;
    }
};
