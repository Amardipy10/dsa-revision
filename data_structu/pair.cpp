#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Ek vector jiske andar int, int ke pairs hain
    vector<pair<int, int>> v;

    // Vector mein values push karna
    v.push_back({10, 1}); // 10 health hai, 1 uska index hai
    v.push_back({5, 2});  // 5 health hai, 2 uska index hai
    v.push_back({20, 3});

    // Loop laga kar print karna
    for(int i = 0; i < v.size(); i++) {
        cout << "Health: " << v[i].first << " | Index: " << v[i].second << endl;
    }

    return 0;
}