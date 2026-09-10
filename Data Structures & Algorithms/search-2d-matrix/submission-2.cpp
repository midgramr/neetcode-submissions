#define sz(a) (int)(a).size()
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = sz(matrix), m = sz(matrix[0]);
        // Treat the matrix like a 1D array
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int k = l + (r - l) / 2;
            int i = k / m, j = k % m;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                l = k + 1;
            } else {
                r = k - 1;
            }
        }
        return false;
    }
};
