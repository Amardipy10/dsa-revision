#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            if(arr[i]==k){
                flag=true;
            }
        }
        if(flag==true){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }
    return 0;
}