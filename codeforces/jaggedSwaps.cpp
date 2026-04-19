#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int t;cin>>t;
        int n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        if(is_sorted(arr.begin(),arr.end())){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    return 0;
}