class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto &e : nums) {
            if (seen.count(e)) return true;
            seen.insert(e);
        }
        return false;
    }
};