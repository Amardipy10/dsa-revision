#include <iostream>
using namespace std;
void solve() {
    long long x, y, k;
    cin >> x >> y >> k;
    long long needed_sticks = (k * y) + k - 1;
    long long stick_trades = (needed_sticks + x - 2) / (x - 1);
    long long total_trades = stick_trades + k;
    cout << total_trades << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}