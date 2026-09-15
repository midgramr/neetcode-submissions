#define sz(a) (int)(a).size()

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = sz(edges);
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1);
        for (auto edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            indeg[a]++; indeg[b]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indeg[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto nei : adj[node]) {
                --indeg[nei];
                if (indeg[nei] == 1) q.push(nei);
            }
        }

        unordered_set<int> cycle;
        for (int i = 1; i <= n; ++i) {
            if (indeg[i] > 1) cycle.insert(i);
        }

        for (int i = n - 1; i >= 0; --i) {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1])) {
                return edges[i];
            }
        }
        return {};
    }
};
