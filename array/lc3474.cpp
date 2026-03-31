
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int L = n + m - 1;
        string word(L, ' ');
        vector<bool> fixed(L, false);

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int k = 0; k < m; ++k) {
                    if (word[i + k] != ' ' && word[i + k] != str2[k]) {
                        return "";
                    }
                    word[i + k] = str2[k];
                    fixed[i + k] = true;
                }
            }
        }

        vector<vector<int>> vec(L);
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                int last_free = -1;
                for (int k = i + m - 1; k >= i; --k) {
                    if (!fixed[k]) {
                        last_free = k;
                        break;
                    }
                }
                if (last_free != -1) {
                    vec[last_free].push_back(i);
                } else {
                    bool match = true;
                    for (int k = 0; k < m; ++k) {
                        if (word[i + k] != str2[k]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) return "";
                }
            }
        }

        for (int j = 0; j < L; ++j) {
            if (!fixed[j]) {
                bool found = false;
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[j] = c;
                    bool ok = true;
                    for (int i : vec[j]) {
                        bool match = true;
                        for (int k = 0; k < m; ++k) {
                            if (word[i + k] != str2[k]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        found = true;
                        break;
                    }
                }
                if (!found) return "";
            }
        }

        return word;
    }
};