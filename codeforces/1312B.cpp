#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int y=n;
        while(y--){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j-arr[j];
                int l=i-arr[i];
                if(k==l){
                    swap(arr[i],arr[j]);
                }
            }
        }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
}