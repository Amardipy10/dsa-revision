#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> prefX(m, vector<int>(n, 0));
        vector<vector<int>> prefY(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int xVal = (grid[i][j] == 'X' ? 1 : 0);
                int yVal = (grid[i][j] == 'Y' ? 1 : 0);

                int upX = (i > 0) ? prefX[i - 1][j] : 0;
                int leftX = (j > 0) ? prefX[i][j - 1] : 0;
                int diagX = (i > 0 && j > 0) ? prefX[i - 1][j - 1] : 0;

                int upY = (i > 0) ? prefY[i - 1][j] : 0;
                int leftY = (j > 0) ? prefY[i][j - 1] : 0;
                int diagY = (i > 0 && j > 0) ? prefY[i - 1][j - 1] : 0;

                prefX[i][j] = xVal + upX + leftX - diagX;
                prefY[i][j] = yVal + upY + leftY - diagY;

                if (prefX[i][j] > 0 && prefX[i][j] == prefY[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};