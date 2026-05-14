#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length(), L = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = 0;
            while (i + k < n && j + k < m && a[i + k] == b[j + k]) k++;
            L = max(L, k);
        }
    }
    cout << n + m - 2 * L << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}