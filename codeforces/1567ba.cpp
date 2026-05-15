#include <iostream>
using namespace std;
int computeXOR(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; 
}
void solve() {
    int a, b;
    cin >> a >> b;
    int x = computeXOR(a - 1);
    int y = x ^ b;
    if (y == 0) {
        cout << a << "\n";
    }
    else if (y == a) {
        cout << a + 2 << "\n";
    }
    else {
        cout << a + 1 << "\n";
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