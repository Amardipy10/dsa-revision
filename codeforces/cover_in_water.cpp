#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        int dotCount = 0;
        int maxSegment = 0;
        
        for (int i = 0; i < n; ) {
            if (s[i] == '#') {
                i++;
                continue;
            }
            
            int j = i;
            while (j < n && s[j] == '.') j++;
            
            int len = j - i;
            dotCount += len;
            maxSegment = max(maxSegment, len);
            
            i = j;
        }
        
        if (dotCount == 0) {
            cout << 0 << "\n";
        } else if (maxSegment >= 3) {
            cout << 2 << "\n";
        } else {
            cout << dotCount << "\n";
        }
    }
    
    return 0;
}