#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string x, s;
        cin >> x >> s; 
        
        int ans = 0;
        
        while (x.size() < s.size()) {
            x += x;
            ans++;
        }
        
        if (x.find(s) != string::npos) {
            cout << ans << endl;
            continue;
        }
        x += x;
        ans++;
        
        if (x.find(s) != string::npos) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}