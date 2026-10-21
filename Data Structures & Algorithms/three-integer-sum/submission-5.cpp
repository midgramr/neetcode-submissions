#define sz(a) (int)(a).size()

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Idea: sort, then fix one pointer and run 2 pointers on the rest of the array
        // To avoid duplicates:
        // - Only visit unique values with the fixed left pointer
        // - When running 2 pointers, skip duplicate elements when a triplet is found
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < sz(nums) - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = sz(nums) - 1;
            while (l < r) {
                int cur = nums[i] + nums[l] + nums[r];
                if (cur < 0) {
                    ++l;
                } else if (cur > 0) {
                    --r;
                } else {
                    triplets.push_back({nums[i], nums[l], nums[r]});
                    do {
                        ++l;
                    } while (l < r && nums[l] == nums[l - 1]);
                }
            }
        }
        return triplets;
    }
};
