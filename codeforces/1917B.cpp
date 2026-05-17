#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> seen(26, false);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int char_index = s[i] - 'a';
        if (!seen[char_index]) {
            seen[char_index] = true;
            ans += (n - i);
        }
    }
    cout << ans <<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}