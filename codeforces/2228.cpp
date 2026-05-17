#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int zero_cnt = 0, one_cnt = 0, two_cnt = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 0)
                zero_cnt++;
            else if (a[i] == 1)
                one_cnt++;
            else if (a[i] == 2)
                two_cnt++;
        }
        int pairs = min(one_cnt, two_cnt);
        cout << zero_cnt+pairs+((one_cnt-pairs)/3)+((two_cnt-pairs)/3)<<endl;
    }
    return 0;
}