class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman ford relaxes up to V - 1 edges, since the longest simple path has length V - 1
        // This naturally allows us to limit the number of edges on any path we consider, but it requires a slight modification: when creating the shortest distances on each iteration, we need to store them into a temporary array, otherwise it's possible that we create a path on a single iteration that adds more than 1 additional edge
        vector<int> minDist(n, INT_MAX / 2);
        minDist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> tmp{minDist};
            for (auto edge : flights) {
                auto from = edge[0], to = edge[1], cost = edge[2];
                if (minDist[from] + cost < tmp[to]) {
                    tmp[to] = minDist[from] + cost;
                }
            }
            std::swap(minDist, tmp);
        }
        return minDist[dst] == INT_MAX / 2 ? -1 : minDist[dst];
    }
};
