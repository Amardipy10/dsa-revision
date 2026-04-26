#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        int maxseg=0;
        int seg=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]<=k){
                seg++;
            }
            else{
                maxseg=max(maxseg,seg);
                seg=0;
            }
        }
        cout<<n-maxseg;
    }
}