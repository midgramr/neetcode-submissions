#define sz(a) (int)(a).size()

class Solution {
    vector<pair<int,int>> off{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = sz(grid), n = sz(grid[0]);

        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        int d = 1;
        while (!q.empty()) {
            int size = sz(q);
            for (int k = 0; k < size; ++k) {
                auto [i, j] = q.front(); q.pop();
                for (auto [di, dj] : off) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == -1)
                        continue;
                    if (d < grid[ni][nj]) {
                        grid[ni][nj] = d;
                        q.push({ni, nj});
                    }
                }
            }
            ++d;
        }
    }
};
