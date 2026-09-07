#define sz(a) (int)(a).size()

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < sz(numbers); ++i) {
            int e = numbers[i];
            if (seen[target - e] != 0) {
                return {seen[target - e], i + 1};
            }
            seen[e] = i + 1;
        }
        return {};
    }
};
