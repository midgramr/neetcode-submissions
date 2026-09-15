#define sz(a) (int)(a).size()

class Solution {
public:
    bool check(vector<vector<int>> &edges, int remove) {
        int n = sz(edges);
        vector<vector<int>> adj(n + 1);
        
        for (int i = 0; i < n; ++i) {
            if (i == remove) continue;
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // Check if the graph is connected
        vector<bool> seen(n + 1);
        function<void(int)> dfs = [&](int node) {
            if (seen[node]) return;
            seen[node] = true;
            for (auto nei : adj[node]) {
                dfs(nei);
            }
        };

        dfs(1);
        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) return false;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Input is small enough than an O(n^2) solution would work
        int n = sz(edges);
        for (int i = n - 1; i >= 0; --i) {
            if (check(edges, i)) return edges[i];
        }
        return {};
    }
};
