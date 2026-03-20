#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int rowLimit = m - k + 1;
        int colLimit = n - k + 1;
        vector<vector<int>> ans(rowLimit, vector<int>(colLimit));

        for (int i = 0; i < rowLimit; ++i) {
            for (int j = 0; j < colLimit; ++j) {
                vector<int> values;
                values.reserve(k * k);
                
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        values.push_back(grid[r][c]);
                    }
                }

                sort(values.begin(), values.end());
                values.erase(unique(values.begin(), values.end()), values.end());

                if (values.size() < 2) {
                    ans[i][j] = 0;
                } else {
                    int minVal = INT_MAX;
                    for (size_t idx = 0; idx < values.size() - 1; ++idx) {
                        minVal = min(minVal, values[idx + 1] - values[idx]);
                    }
                    ans[i][j] = minVal;
                }
            }
        }

        return ans;
    }
};