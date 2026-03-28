class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, ' ');
        char c = 'a';
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (c > 'z') return "";
                for (int j = i; j < n; ++j) {
                    if (lcp[i][j] > 0 && s[j] == ' ') {
                        s[j] = c;
                    }
                }
                c++;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int expected = 0;
                if (s[i] == s[j]) {
                    expected = 1 + ((i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] : 0);
                }
                if (lcp[i][j] != expected) {
                    return "";
                }
            }
        }
        
        return s;
    }
};