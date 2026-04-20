#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       int a,b,c;
       cin>>a>>b>>c;
       if(a+c/2+c%2>b+c/2) cout<<"First"<<endl;
       else cout<<"Second"<<endl;
    }
    return 0;
}