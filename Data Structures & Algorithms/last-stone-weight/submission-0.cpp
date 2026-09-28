#define sz(a) (int)(a).size()

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (sz(pq) >= 2) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != b) {
                pq.push(max(a, b) - min(a, b));
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
