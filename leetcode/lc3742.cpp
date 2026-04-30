class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        for (int i = 0; i < m; ++i) {
            vector<vector<int>> next_dp(n, vector<int>(k + 1, -1));
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    next_dp[0][0] = 0;
                    continue;
                }

                int val = grid[i][j];
                int score = (val == 1) ? 1 : (val == 2 ? 2 : 0);
                int cost = (val > 0) ? 1 : 0;

                for (int c = cost; c <= k; ++c) {
                    int prev_max = -1;
                    if (i > 0) {
                        prev_max = max(prev_max, dp[j][c - cost]);
                    }
                    if (j > 0) {
                        prev_max = max(prev_max, next_dp[j - 1][c - cost]);
                    }
                    
                    if (prev_max != -1) {
                        next_dp[j][c] = prev_max + score;
                    }
                }
            }
            dp = std::move(next_dp);
        }

        int max_score = -1;
        for (int c = 0; c <= k; ++c) {
            max_score = max(max_score, dp[n - 1][c]);
        }
        return max_score;
    }
};