class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // DAG != valid tree
        // Idea: do DFS and make sure every edge is a discovery edge; no need to differentiate between forward, cross, and back edges
        // During DFS, pass in the previous node so that isn't considered a cycle
        vector<bool> seen(n);
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // Returns false if non-discovery edge discovered
        function<bool(int, int)> dfs = [&](int node, int prev) -> bool {
            if (seen[node]) return false;
            seen[node] = true;
            for (auto nei : adj[node]) {
                if (nei == prev) continue;
                if (!dfs(nei, node)) return false;
            }
            return true;
        };

        // Edge case: disconnected graph; start DFS from an arbitrary node and check that every node gets visited with no cycles
        if (!dfs(0, -1)) return false;
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) return false;
        }
        return true;
    }
};
