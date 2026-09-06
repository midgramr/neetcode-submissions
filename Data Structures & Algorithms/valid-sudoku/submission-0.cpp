class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // To check whether a row/col/box is valid, I need to check that
        // 1. no duplicates
        // 2. numbers are in the expected range

        int n = 9;
        for (int i = 0; i < n; ++i) {
            vector<bool> seen(9);
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;
                if (seen[board[i][j] - '1']) return false;
                seen[board[i][j] - '1'] = true;
            }
        }

        for (int i = 0; i < n; ++i) {
            vector<bool> seen(9);
            for (int j = 0; j < n; ++j) {
                if (board[j][i] == '.') continue;
                if (seen[board[j][i] - '1']) return false;
                seen[board[j][i] - '1'] = true;
            }
        }

        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                vector<bool> seen(9);
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (board[i + k][j + l] == '.') continue;
                        if (seen[board[i + k][j + l] - '1']) return false;
                        seen[board[i + k][j + l] - '1'] = true;
                    }
                }
            }
        }

        return true;
    }
};
