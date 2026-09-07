#define sz(a) (int)(a).size()

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // NOTE: The list is sorted
        for (int i = 0, j = sz(numbers) - 1; i < j;) {
            int cur = numbers[i] + numbers[j];
            if (cur == target) {
                return {i + 1, j + 1};
            } else if (cur < target) {
                ++i;
            } else {
                --j;
            }
        }
        return {};
    }
};
