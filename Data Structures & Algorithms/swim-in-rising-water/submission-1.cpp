#define sz(a) (int)(a).size()

class Solution {
    vector<pair<int,int>> off{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Idea: binary search + BFS
        int n = sz(grid);
        
        function<bool(int)> check = [&](int t) -> bool {
            vector<vector<bool>> seen(n, vector<bool>(n));
            queue<pair<int,int>> q;
            if (grid[0][0] > t) return false;
            q.push({0, 0});
            while (!q.empty()) {
                auto [i, j] = q.front(); q.pop();
                for (auto [di, dj] : off) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n || seen[ni][nj] || grid[ni][nj] > t)
                        continue;
                    seen[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
            return seen[n - 1][n - 1];
        };

        int l = 0, r = n * n - 1;
        // Search for first value of t such that the bottom right corner is reachable
        while (l < r) {
            int t = l + (r - l) / 2;
            if (check(t)) {
                r = t;
            } else {
                l = t + 1;
            }
        }
        return l;
    }
};
