#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<int>arr(n);
        int sum=0;
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        
        if(sum%2 == 1){
            cout<<"YES"<<endl;
        }
        else if(n%2==1 && k%2 == 1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}