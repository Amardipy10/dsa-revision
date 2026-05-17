#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    long long ans = 1;
    long long MOD = 1e9 + 7;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] > b[i]) {
            j++;
        }
        long long choices = j - i;
        if (choices <= 0) {
            ans = 0;
            break;
        }
        ans = (ans * choices) % MOD;
    }
    cout << ans << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}