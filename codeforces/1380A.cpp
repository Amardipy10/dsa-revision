#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin >> t;
while (t--)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    bool flag=false;
    for (int j = 1; j < n; j++)
    {

        int i = 0, k = j + 1;
        for(i = 0; i < j ; i++ ){
            if(arr[i] < arr[j]){
                break;
            }
        }

        for(k = j + 1; k < n; k++){
            if(arr[j] > arr[k]) {
                break;
            }
        }

        if(i < j && k < n){
            flag = true;
            ans = {i, j , k};
        }
    }
    if (!flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << ans[i] + 1<< " ";
        }
        cout << endl;
    }
}
}
