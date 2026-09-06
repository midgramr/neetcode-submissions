class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Convert to (count, num)
        unordered_map<int, int> cnts;
        for (auto &e : nums) {
            cnts[e]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto &[num, cnt] : cnts) {
            pq.push({cnt, num});
        }

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};
