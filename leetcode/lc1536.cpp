class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing_zeros(n);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            trailing_zeros[i] = count;
        }
        int total_swaps = 0;
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i;
            int found_idx = -1;
            for (int j = i; j < n; ++j) {
                if (trailing_zeros[j] >= target) {
                    found_idx = j;
                    break;
                }
            }
            if (found_idx == -1) return -1;
            total_swaps += (found_idx - i);
            int temp = trailing_zeros[found_idx];
            for (int k = found_idx; k > i; --k) {
                trailing_zeros[k] = trailing_zeros[k - 1];
            }
            trailing_zeros[i] = temp;
        }
        return total_swaps;
    }
};