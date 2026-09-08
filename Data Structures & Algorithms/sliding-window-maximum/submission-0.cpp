#define sz(a) (int)(a).size()
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> window;
        vector<int> ans;
        for (int i = 0, j = 0; j < sz(nums); ++j) {
            window[nums[j]]++;
            if (j - i + 1 == k) {
                ans.push_back(prev(window.end())->first);
                window[nums[i]]--;
                if (window[nums[i]] == 0) {
                    window.erase(nums[i]);
                }
                ++i;
            }
        }
        return ans;
    }
};
