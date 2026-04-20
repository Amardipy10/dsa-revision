#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (!is_sorted(arr.begin(), arr.end())) {
            cout << 0 << endl;
            continue;
        }

        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        cout << (minDiff / 2 + 1) << endl;
    }

    return 0;
}