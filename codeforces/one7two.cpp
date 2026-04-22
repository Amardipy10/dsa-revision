#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        int sum = accumulate(arr.begin(), arr.end(), 0);
        int halfsum = sum / 2;

        int newsum = 0;
        int i = 0;

        while(i < n && newsum < halfsum){
            newsum += arr[i];
            i++;
        }

        if(newsum == halfsum){
            cout << i << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}