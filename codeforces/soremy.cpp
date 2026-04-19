#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
        }

        if (freq.size() > 2)
        {
            cout << "No" << endl;
            continue;
        }

        if (freq.size() == 1)
        {
            cout << "Yes" << endl;
            continue;
        }

        // exactly 2 elements
        vector<int> f;
        for (auto &p : freq)
        {
            f.push_back(p.second);
        }

        if (abs(f[0] - f[1]) <= 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}