class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9)),
            cols(9, vector<bool>(9));
        map<pair<int, int>, vector<bool>> boxes;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                boxes[{i, j}] = vector<bool>(9);
            }
        }
        
        int n = 9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;
                int e = board[i][j] - '1';
                if (rows[i][e] || cols[j][e] || boxes[{i / 3, j / 3}][e]) return false;
                rows[i][e] = cols[j][e] = boxes[{i / 3, j / 3}][e] = true;
            }
        }

        return true;
    }
};
