#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
    long long n;
    cin >> n;
    long long ans = (337LL * n) % MOD;
    ans = (ans * (n + 1)) % MOD;
    ans = (ans * (4LL * n - 1)) % MOD;
    
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}