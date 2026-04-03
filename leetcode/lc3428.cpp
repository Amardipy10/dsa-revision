class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        long long dp[501][501][3];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] = -1e18;
                }
            }
        }

        for (int k = 0; k < 3; ++k) {
            long long val = coins[0][0];
            if (k == 0) {
                dp[0][0][k] = val;
            } else {
                dp[0][0][k] = max(val, 0LL);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (dp[i][j][k] == -1e18) continue;

                    int dirs[2][2] = {{0, 1}, {1, 0}};
                    for (auto& d : dirs) {
                        int ni = i + d[0];
                        int nj = j + d[1];

                        if (ni < m && nj < n) {
                            long long next_val = coins[ni][nj];
                            
                            dp[ni][nj][k] = max(dp[ni][nj][k], dp[i][j][k] + next_val);

                            if (k + 1 < 3 && next_val < 0) {
                                dp[ni][nj][k + 1] = max(dp[ni][nj][k + 1], dp[i][j][k]);
                            }
                        }
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};