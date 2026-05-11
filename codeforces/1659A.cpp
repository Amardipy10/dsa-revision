#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,r,b;
        cin>>n>>r>>b;
        string ans="";
        while(r!=0){
            if(r>3){
                ans+="RRR";
                r-=3;
                ans+="B";
                b--;

            }
            else{
                ans+='R'*r;
                r=0;
            }
        }
        ans+='B'*b;
        cout<<ans<<endl;
    }

}