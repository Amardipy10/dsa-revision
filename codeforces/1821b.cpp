#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] != b[i]) {
            r= i;
            break;
        }
    }
    while(l > 0 && b[l - 1] <= b[l]) {
    l--;
    }
    while(r < n - 1 && b[r] <= b[r + 1]) {
    r++;
    }
    cout << l + 1 << " " << r + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}