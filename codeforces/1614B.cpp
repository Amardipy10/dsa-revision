#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main (){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>>a(n);
        vector<pair<int,int>>b,c;
        for(int i=0;i<n;i++){
            int x; cin >> x;
            a[i] = {x, i};
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

        vector<int> ans(n);
        
        for(int i=0;i<b.size();i++){
            total_time+=((i+1)*2*b[i].first);
        }
        for(int i=0;i<c.size();i++){
            total_time+=((i+1)*2*c[i].first);
        }
        cout<<total_time<<endl;


        
        int z=b.size();
        int x=c.size();
        for(int i=0;i<b.size();i++){
            ans[b[i].second] = i + 1;
        }
    
        reverse(c.begin(), c.end());
        for(int i = 0; i < c.size(); i++){
            ans[c[i].second] = -(i + 1);
        }

        cout <<  0 << " ";
        for(auto i : ans) cout << i << " ";
        cout<<endl;
    }
}