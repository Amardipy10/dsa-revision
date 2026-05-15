#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<string> unique_strings;
void stringcount(string s) {
    if (unique_strings.count(s)) {
        return;
    }
    unique_strings.insert(s);
    if (s.length() == 0) {
        return;
    }
    if (s.length() == 1) {
        string s1 = s;
        s1.erase(0, 1);
        stringcount(s1);
        return;
    }
    string s1 = s;
    s1.erase(0, 1);
    stringcount(s1);
    string s2 = s;
    s2.erase(1, 1);
    stringcount(s2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;
        string s;
        cin >> s;
        unique_strings.clear(); 
        stringcount(s);
        cout << unique_strings.size() << endl;
    }
    return 0;
}