#define sz(a) (int)(a).size()

class DSU {
    vector<int> par, size;
    
public:
    DSU(int n) : par(n), size(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int findSet(int x) {
        if (par[x] == x) return x;
        return par[x] = findSet(par[x]);
    }

    // Return true if union is successful
    bool unionSet(int x, int y) {
        int parX = findSet(x), parY = findSet(y);
        if (parX == parY) return false;
        if (size[parX] <= size[parY]) {
            par[parX] = parY;
            size[parY] += size[parX];
        } else {
            par[parY] = parX;
            size[parX] += size[parY];
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // MST problem; enumate all edges by checking all pairs
        // DSU implementation
        int n = sz(points);
        vector<vector<int>> adj(n);

        vector<vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int cost = abs(x2 - x1) + abs(y2 - y1);
                edges.push_back({cost, i, j});
            }
        }

        DSU dsu(n);
        long long cost = 0;

        sort(edges.begin(), edges.end());
        for (auto edge : edges) {
            if (dsu.unionSet(edge[1], edge[2])) {
                cost += edge[0];
            }
        }

        return cost;
    }
};
