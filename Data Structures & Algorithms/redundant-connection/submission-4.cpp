#define sz(a) (int)(a).size()

class DSU {
private:
    vector<int> size, par;

public:
    DSU(int n) : size(n, 1), par(n) {
        iota(par.begin(), par.end(), 0);
    }

    int findSet(int x) {
        if (par[x] == x) return x;
        return par[x] = findSet(par[x]);
    }

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = sz(edges);
        DSU dsu(n + 1);
        for (auto edge : edges) {
            int a = edge[0], b = edge[1];
            if (!dsu.unionSet(a, b)) return edge;
        }
        return {};
    }
};
