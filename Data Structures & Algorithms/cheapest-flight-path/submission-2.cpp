#define sz(a) (int)(a).size()
using vi = vector<int>;

class Solution {
public:
    int findCheapestPrice(int n, vector<vi>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto edge : flights) {
            auto from = edge[0], to = edge[1], cost = edge[2];
            adj[from].push_back({to, cost});
        }
        
        // Track minDist for every (node, unweighted distance)
        vector<vi> minDist(n, vi(n + 1, INT_MAX));
        minDist[src][0] = 0;

        // State: {weighted dist, unweighted dist, node}
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        pq.push({0, 0, src});

        while (!pq.empty()) {
            auto state = pq.top(); pq.pop();
            auto wd = state[0], ud = state[1], node = state[2];
            // The first time we encounter the dst here, regardless of ud, is the shortest valid weighted path
            if (node == dst) {
                return wd;
            }
            if (wd > minDist[node][ud]) continue;
            for (auto [nei, w] : adj[node]) {
                // Prune paths where the unweighted distance is too large
                if (nei != dst && ud == k) continue;
                if (wd + w < minDist[nei][ud + 1]) {
                    minDist[nei][ud + 1] = wd + w;
                    pq.push({wd + w, ud + 1, nei});
                }
            }
        }
        return -1;
    }
};
