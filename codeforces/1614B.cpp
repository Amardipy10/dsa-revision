#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main (){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n);
        vector<int>b,c;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int total_time=0;
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<n;i++){
            if(i%2==0){
                b.push_back(a[i]);
            }
            else{
                c.push_back(a[i]);
            }
        }
        
        for(int i=0;i<b.size();i++){
            total_time+=((i+1)*2*b[i]);
        }
        for(int i=0;i<c.size();i++){
            total_time+=((i+1)*2*c[i]);
        }
        cout<<total_time<<endl;
        
        int z=b.size();
        int x=c.size();
        for(int i=1;i<=b.size();i++){
            cout<<i<<" ";
        }
        cout<<0<<" ";
        for(int i=-(c.size());i<0;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}