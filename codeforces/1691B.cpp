#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n);
        vector<int>ans(n);
        bool flag=true;
        for(int i=0;i<n;i++){
            ans[i]=i+1;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if(n==1){
                flag=false;
            }
            if(arr[i]==arr[i+1]){
                count++;
                swap(ans[i],ans[i+1]);
            }
            else if(arr[i]!=arr[i+1]&&count==0){
                flag=false;
            }
            else if(n%2!=0&& arr[n-1]!=arr[n-2]){
                flag=false;
            }
            else{
                count=0;
            }
        }
        if(!flag){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
}