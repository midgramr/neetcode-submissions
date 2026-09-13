#define sz(a) (int)(a).size()

class Solution {
    vector<pair<int, int>> off{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m));

        function<void(int, int)> dfs = [&](int i, int j) {
            if (seen[i][j]) return;
            seen[i][j] = true;
            for (auto [di, dj] : off) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (grid[ni][nj] == '1') dfs(ni, nj);
            }
        };

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    cnt += !seen[i][j];
                    dfs(i, j);
                }
            }
        }

        return cnt;
    }
};
