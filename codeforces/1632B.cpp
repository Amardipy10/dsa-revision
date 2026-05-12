#include<iostream>
using namespace std;
void solve(){
    int n;
    cin>>n;

    int k=1;
    while(k*2<n){
        k*=2;
    }
    for(int i=n-1;i>=k;--i){
        cout<<i<<" ";
    }
    for(int i=0;i<k;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}