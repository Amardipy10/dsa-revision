#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    int neg_count = 0;
    long long total_abs_sum = 0;
    int min_abs_val = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            if (val < 0) neg_count++;
            total_abs_sum += abs(val);
            min_abs_val = min(min_abs_val, abs(val));
        }
    }
    if (neg_count % 2 == 0) {
        cout << total_abs_sum << endl;
    } else {
        cout << total_abs_sum - 2 * min_abs_val << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}