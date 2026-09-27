#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using pii = pair<int,int>;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Idea: sort the intervals and queries; use a min-heap to store intervals ordered by length. The heap should also store the end time of each interval so intervals that don't include the current query can be popped. For each query, add every interval that begins before the current query that hasn't been seen yet (every interval is added and popped at most once). Queries need to be sorted so that once an interval is popped we can be sure that it can't be relevant to any future query.

        vector<int> sortedQs{queries};
        sort(all(sortedQs));
        sort(all(intervals));

        // Store (interval length, interval end)
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // key = query, value = query answer
        // Needed since we worked with queries in sorted order
        unordered_map<int, int> qs;
        
        // Iterator over sorted intervals
        int i = 0;
        for (auto q : sortedQs) {
            // Separate pushes and pops for simplicity?
            while (i < sz(intervals) && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }
            qs[q] = pq.empty() ? -1 : pq.top().first;
        }

        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(qs[q]);
        }
        return ans;
    }
};
