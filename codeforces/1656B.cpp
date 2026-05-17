#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = 1;
    bool found = false;
    while (i < n && j < n) {
        if (i == j) {
            j++;
            continue;
        }
        int diff = a[j] - a[i];
        if (diff == k) {
            found = true;
            break;
        } 
        else if (diff < k) {
            j++;
        } 
        else {
            i++;
        }
    }
    if (found) {
        cout << "YES"<<endl;
    } else {
        cout << "NO"<<endl;
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