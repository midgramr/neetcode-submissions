class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // In a hashtable, for each number, start the length of the longest sequence found so far that starts at that number if it's a sequence start or ends at that number if it's a sequence end
        // Numbers in the middle of a sequence may have a stale sequence length value stored in the hashtable
        unordered_map<int, int> m;
        int res = 0;
        for (auto e : nums) {
            if (!m[e]) {
                m[e] = 1 + m[e - 1] + m[e + 1];
                res = max(res, m[e]);
                m[e - m[e - 1]] = m[e + m[e + 1]] = m[e];
            }
        }
        return res;
    }
};
