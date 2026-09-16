using pii = pair<int,int>;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Construct SSSP tree and find the largest distance
        // Each edge is stored as (dst, weight)
        vector<vector<pii>> adj(n + 1);
        for (auto edge : times) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // (dist, node); must be min heap
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            for (auto [nei, w] : adj[node]) {
                if (d + w < dist[nei]) {
                    dist[nei] = d + w;
                    pq.push({d + w, nei});
                }
            }
        }

        // Edge case: check that graph is connected
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
