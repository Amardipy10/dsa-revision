class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // We only need to iterate through the first half of the submatrix rows
        // to swap them with the corresponding rows in the second half.
        for (int i = 0; i < k / 2; ++i) {
            for (int j = 0; j < k; ++j) {
                // Swap grid[row_top][col] with grid[row_bottom][col]
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        return grid;
    }
};