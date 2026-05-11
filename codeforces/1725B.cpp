#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    int start = 0;
    int end = n - 1;
    int teams = 0;

    while(start <= end) {
        int power = arr[start];
        int need = d / power + 1;
        if(start + need - 1 <= end) {
            teams++;
            start++;
            end -= (need - 1);
        }
        else {
            break;
        }
    }
    cout << teams << endl;
}