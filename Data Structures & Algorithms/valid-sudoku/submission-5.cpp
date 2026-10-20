class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate rows, columns, then boxes
        // For boxes, can hardcode fixed offsets and iterate through the top-left corners of the boxes

        for (int i = 0 ; i < 9; ++i) {
            vector<bool> seen(9);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '1';
                if (seen[c]) {
                    return false;
                }
                seen[c] = true;
            }
        }

        for (int j = 0 ; j < 9; ++j) {
            vector<bool> seen(9);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '1';
                if (seen[c]) {
                    return false;
                }
                seen[c] = true;
            }
        }

        for (int si = 0; si < 9; si += 3) {
            for (int sj = 0; sj < 9; sj += 3) {
                vector<bool> seen(9);
                for (int di = 0; di < 3; ++di) {
                    for (int dj = 0; dj < 3; ++dj) {
                        int i = si + di, j = sj + dj;
                        if (board[i][j] == '.') continue;
                        int c = board[i][j] - '1';
                        if (seen[c]) return false;
                        seen[c] = true;
                    }
                }
            }
        }

        return true;
    }
};
