#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compareMonsters(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first; 
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> monsters(n);
    
    for (int i = 0; i < n; i++) {
        int health;
        cin >> health;
        int rem = health % k;
        if (rem == 0) {
            rem = k;
        }
        monsters[i] = {rem, i + 1};
    }
    sort(monsters.begin(), monsters.end(), compareMonsters);
    for (int i = 0; i < n; i++) {
        cout << monsters[i].second << " ";
    }
    cout <<endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t > 0) {
        solve();
        t--;
    }
    
    return 0;
}