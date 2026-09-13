#define sz(a) (int)(a).size()

class Solution {
    vector<pair<int, int>> off{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n));

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (seen[i][j]) return 0;
            seen[i][j] = true;
            int total = 1;
            for (auto [di, dj] : off) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != 1)
                    continue;
                total += dfs(ni, nj);
            }
            return total;
        };

        int hi = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                hi = max(hi, dfs(i, j));
            }
        }

        return hi;
    }
};
