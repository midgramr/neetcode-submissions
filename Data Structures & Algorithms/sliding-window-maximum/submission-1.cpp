#define sz(a) (int)(a).size()

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (int i = 0; i < sz(nums); ++i) {
            if (i >= k) {
                while (!pq.empty() && pq.top().second <= i - k) {
                    pq.pop();
                }
            }
            pq.push({nums[i], i});
            if (i >= k - 1) {
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};
