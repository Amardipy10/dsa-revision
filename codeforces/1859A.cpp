#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int mn = *min_element(arr.begin(), arr.end());

        vector<int> brr, crr;

        for (int x : arr) {
            if (x == mn) brr.push_back(x);
            else crr.push_back(x);
        }

        if (crr.empty()) {
            cout << -1 << '\n';
        } else {
            cout << brr.size() << " " << crr.size() << '\n';

            for (int x : brr) cout << x << " ";
            cout << '\n';

            for (int x : crr) cout << x << " ";
            cout << '\n';
        }
    }

    return 0;
}