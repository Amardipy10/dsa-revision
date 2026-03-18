 #include <vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int currentSum = grid[i][j];
                
                if (i > 0) {
                    currentSum += prefixSum[i - 1][j];
                }
                if (j > 0) {
                    currentSum += prefixSum[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    currentSum -= prefixSum[i - 1][j - 1];
                }
                
                if (currentSum <= k) {
                    prefixSum[i][j] = currentSum;
                    count++;
                } else {
                    prefixSum[i][j] = k + 1;
                }
            }
        }
        
        return count;
    }
};