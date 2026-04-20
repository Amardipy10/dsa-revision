#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n);
        int maxZero=0;
         int Zero=0;
        for(int i=0;i<n;i++){
           
            cin>>arr[i];
            if(arr[i]==0){
                Zero++;
            }
            else{
                maxZero=max(maxZero,Zero);
                Zero=0;
            }
        }
         maxZero=max(maxZero,Zero);
        cout<<maxZero<<endl;
    }
    return 0;
}