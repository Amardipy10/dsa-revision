class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        
        for (int i = 0; i < m; i++) {
            vector<int> shifted(n);
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0)
                    shifted[j] = mat[i][(j + k) % n];
                else
                    shifted[j] = mat[i][(j - k % n + n) % n];
            }
            for (int j = 0; j < n; j++) {
                if (shifted[j] != mat[i][j])
                    return false;
            }
        }
        return true;
    }
};