#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int ans = k; 
        int cnt = 0; 

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            
            int r = x % k;
            if (r == 0) {
                ans = 0;
            } else {
                ans = min(ans, k - r);
            }
            
            if (x % 2 == 0) {
                cnt++;
            }
        }

        if (k == 4) {
            int ans2;
            if (cnt >= 2) {
                ans2 = 0;
            } else if (cnt == 1) {
                ans2 = 1;
            } else {
                ans2 = 2; 
            }
            
            ans = min(ans, ans2);
        }

        cout << ans << "\n";
    }
    return 0;
}