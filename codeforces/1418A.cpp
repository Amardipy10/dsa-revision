#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;

        int ans=((k+k*y-1)/x-1)+k;
        cout<<ans<<endl;
    }
}