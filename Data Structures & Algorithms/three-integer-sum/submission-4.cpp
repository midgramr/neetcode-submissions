#define sz(a) (int)(a).size()

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Challenging part is deduplicating triplets
        // There's a way to iterate through the array in such a way that duplicates can be avoided
        // without the help of a data structure

        // 1. Sort the array
        // 2. Fix the left pointer and run 2sum on the right side of the array
        // 3. Increment the left pointer (here's where we need some way of dealing with duplicates).
        // With a given left pointer, I should iterate through all possible triplets so the left
        // pointer can be incremented to the next unique number. When a valid triplet is found, I should
        // unconditionally increment the 2nd pointer until it reaches a new value and run the match again

        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int n = sz(nums);
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1, k = n - 1; j < k;) {
                int cur = nums[i] + nums[j] + nums[k];
                if (cur == 0) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    ++j;
                } else if (cur < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
            // This will take me to the last number in a sequence of identicial numbers
            while (i < n - 2 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return triplets;
    }
};
