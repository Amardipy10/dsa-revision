#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k,b,s;
        cin>>n>>k>>b>>s;
        if(s/k<b|| (s-(n-1)*(k-1)/k>b))return -1;
        vector<int>ans(n-1,0);
        int i=0;
        while(s/k!=b||i!=n-1){
            ans[i]+=k-1;
            s-=k-1;
            i++;
        }
        for(int i=0;i<n-1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<s<<endl;
    }
    return 0;
}