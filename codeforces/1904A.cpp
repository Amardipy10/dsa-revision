#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int a,b;
        cin>>a>>b;
        int k1,k2;
        cin>>k1>>k2;
        int q1,q2;
        cin>>q1>>q2;
        vector<pair<int,int>>v;
        v.push_back({q1+a,q2+b});
        v.push_back({q1+b,q2+a});
        v.push_back({q1+a,q2-b});
        v.push_back({q1-b,q2+a});
        v.push_back({q1-a,q2+b});
        v.push_back({q1+b,q2-a});
        v.push_back({q1-a,q2-b});
        v.push_back({q1-b,q2-a});

        vector<pair<int,int>>v2;
        v2.push_back({k1+a,k2+b});
        v2.push_back({k1+b,k2+a});
        v2.push_back({k1+a,k2-b});
        v2.push_back({k1-b,k2+a});
        v2.push_back({k1-a,k2+b});
        v2.push_back({k1+b,k2-a});
        v2.push_back({k1-a,k2-b});
        v2.push_back({k1-b,k2-a}); 

        int count=0;

        for(int i=0;i<v.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v[i]==v2[j]){
                    count++;
                }
            }
        }
        cout<<count<<endl;

    }
    return 0;
}