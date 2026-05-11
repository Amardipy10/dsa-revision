#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n),brr(n);
        unordered_map<int,int>mp1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp1[arr[i]]=0;
        }
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        int len=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                len++;
            }
            else{

                mp1[arr[i]]=max(mp1[arr[i]],len);
                len=1;
            }
        }
        
        mp1[arr[n-1]]=max(mp1[arr[n-1]],len);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,mp1[arr[i]]);
        }
        len=1;
        for(int i=0;i<n-1;i++){
            if(brr[i]==brr[i+1]){
                len++;  
            }
            else{
                ans=max(ans,mp1[brr[i]]+len);
                len=1;
            }
        }
        ans=max(ans,mp1[brr[n-1]]+len);

        cout<<ans<<endl;
    }
}