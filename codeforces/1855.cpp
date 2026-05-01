#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long interval=0;
        for(long long i=1;i<n;i++){
            if(n%i==0){
                interval++;
            }
            else{
                cout<<interval<<endl;
                break;
            }
        }
    }
};