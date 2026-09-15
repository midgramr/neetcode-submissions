#define sz(a) (int)(a).size()

class Solution {
    vector<pair<int,int>> off{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    void solve(vector<vector<char>>& board) {
        // Start from the edge of the board; for every tile that's an 'O', find every tile it can reach. None of those tiles are capturable
        int m = sz(board), n = sz(board[0]);
        // Can reuse this as a visited set
        vector<vector<bool>> cannot(m, vector<bool>(n));

        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                cannot[i][0] = true;
            }
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                cannot[i][n - 1] = true;
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                cannot[0][j] = true;
            }
            if (board[m - 1][j] == 'O') {
                q.push({m - 1, j});
                cannot[m - 1][j] = true;
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (auto [di, dj] : off) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n
                    || board[ni][nj] == 'X' || cannot[ni][nj])
                    continue;
                cannot[ni][nj] = true;
                q.push({ni, nj});
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!cannot[i][j]) board[i][j] = 'X';
            }
        }
    }
};