#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            while(arr[i]%k<k){
                arr[i]=arr[i]%k;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==0){
                ans.push_back(i);
            }

        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]!=0){
                ans.push_back(i);
            }

        }
        for (int i = 0; i < n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
}