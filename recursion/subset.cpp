#include<iostream>
#include<vector>
using namespace std;

int subset(vector<int> &num,vector<int> &ans,int i){
    if(i==num.size()){
        for(int val:ans){
            cout<<val<<" ";
        }
    }
    ans.push_back(num[i]);
    subset(num,ans,i+1);

    ans.pop_back();
    subset(num,ans,i-1);
}