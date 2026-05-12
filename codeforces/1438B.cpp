#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        unordered_set<int>s;
        vector<int>b(n);
        bool flag=true;
        for(int i=0;i<n;i++){
            if(s.find(b[i])!=s.end()){
                flag=false;
            }
            else{
                s.insert(b[i]);
            }
        }
        if(!flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}