class Solution {
    // JFK -> SFO, ATL
    // SFO -> ATL
    // ATL -> SFO, JFK
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto &edge : tickets) {
            string from = edge[0], to = edge[1];
            adj[from].push_back(to);
        }
        for (auto &[_, edges] : adj) {
            sort(edges.begin(), edges.end(), greater<string>());
        }

        vector<string> path;

        function<void(string)> dfs = [&](string node) {
            while (!adj[node].empty()) {
                auto nei = adj[node].back();
                adj[node].pop_back();
                dfs(nei);
            }
            path.push_back(node);
        };

        dfs("JFK");
        reverse(path.begin(), path.end());
        return path;
    }
};
