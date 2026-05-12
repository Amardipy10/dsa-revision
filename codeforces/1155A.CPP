#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        int k;
        bool flag=false;
        for(int i=0;i<n-1;i++){
            if(s[i]>s[i+1]){
                k=i+1;
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<k<<" "<<k+1;
        }
        else{
            cout<<"NO";
        }
    }
}