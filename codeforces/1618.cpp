#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long gcd1 = a[0]; 
    long long gcd2 = a[1]; 
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            gcd1 = gcd(gcd1, a[i]);
        } else {
            gcd2 = gcd(gcd2, a[i]);
        }
    }
    bool gcd1_valid = true;
    for (int i = 1; i < n; i += 2) {
        if (a[i] % gcd1 == 0) {
            gcd1_valid = false;
            break;
        }
    }

    if (gcd1_valid) {
        cout << gcd1 << "\n";
        return;
    }
    bool gcd2_valid = true;
    for (int i = 0; i < n; i += 2) {
        if (a[i] % gcd2 == 0) {
            gcd2_valid = false;
            break;
        }
    }

    if (gcd2_valid) {
        cout << gcd2 << "\n";
        return;
    }
    cout << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}