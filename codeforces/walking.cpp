#include <iostream>

using namespace std;

void solve() {
    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return;
    if (d < b) {
        cout << -1 << endl;
        return;
    }
    long long up_moves = d - b;
    long long current_x = a + up_moves;
    if (c > current_x) {
        cout << -1 << endl;
    } else {
        long long left_moves = current_x - c;
        cout << up_moves + left_moves << endl;
    }
}

int main() {    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}