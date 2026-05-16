#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    vector<int>a={2,3,4,5,4,32,1,5,31,3};
    unordered_map<int,int>mp;
    int n=a.size();
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    for(auto i:mp){
        cout<<i.first<<" "<<"count"<<i.second<<endl;
    }
    }
