#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t ;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        while(k--){
            int first_min=arr[0];
            int sec_min=0;
            int maxi=arr[0];
            for(int i=1;i<n;i++){
                if(arr[i]<first_min){
                    sec_min=first_min;
                    first_min=arr[i];
                }
                else if(arr[i]>maxi){
                    maxi=arr[i];
                }
            }
            vector<int>ans;
            if(first_min+sec_min<maxi){
            for(int i=0;i<n;i++){
                if(arr[i]==firstmin)
            }}
        }
    }
}