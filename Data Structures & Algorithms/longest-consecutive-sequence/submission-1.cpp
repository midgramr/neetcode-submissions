#define sz(a) (int)(a).size()

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lens;
        int ans = 0;
        for (auto &e : nums) {
            if (lens[e] != 0) continue;
            lens[e] = lens[e - 1] + lens[e + 1] + 1;
            ans = max(ans, lens[e]);
            lens[e - lens[e - 1]] = lens[e + lens[e + 1]] = lens[e];
        }
        return ans;
    }
};
