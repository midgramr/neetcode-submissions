class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Run DFS and the number of trees is the number of components
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnt = 0;
        vector<bool> seen(n);

        function<bool(int)> dfs = [&](int node) -> bool {
            if (seen[node]) return false;
            seen[node] = true;
            for (auto nei : adj[node]) {
                dfs(nei);
            }
            return true;
        };

        for (int i = 0; i < n; ++i) {
            cnt += dfs(i);
        }

        return cnt;
    }
};
