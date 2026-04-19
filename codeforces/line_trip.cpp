#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n + 2);
        arr[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        arr[n + 1] = x;
        int maxi = 0;
        for(int i = 0; i <= n; i++){
            maxi = max(maxi, arr[i + 1] - arr[i]);
        }
        maxi = max(maxi, 2 * (arr[n + 1] - arr[n]));
        cout << maxi << endl;
    }
}