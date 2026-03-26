#include <vector>

using namespace std;

class Solution {
public:
    bool check(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m <= 1) return false;

        vector<int> bot_f(100005, 0);
        vector<int> top_f(100005, 0);
        long long S_bot = 0;
        long long S_top = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bot_f[grid[i][j]]++;
                S_bot += grid[i][j];
            }
        }

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                bot_f[val]--;
                top_f[val]++;
                S_bot -= val;
                S_top += val;
            }

            long long D = S_top - S_bot;
            if (D == 0) return true;

            if (D > 0 && D <= 100000) {
                int target = D;
                if (i == 0) {
                    if (target == grid[0][0] || target == grid[0][n - 1]) return true;
                } else if (n == 1) {
                    if (target == grid[0][0] || target == grid[i][0]) return true;
                } else {
                    if (top_f[target] > 0) return true;
                }
            } else if (D < 0 && -D <= 100000) {
                int target = -D;
                if (i == m - 2) {
                    if (target == grid[m - 1][0] || target == grid[m - 1][n - 1]) return true;
                } else if (n == 1) {
                    if (target == grid[i + 1][0] || target == grid[m - 1][0]) return true;
                } else {
                    if (bot_f[target] > 0) return true;
                }
            }
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (check(grid)) return true;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = grid[i][j];
            }
        }

        return check(transposed);
    }
};