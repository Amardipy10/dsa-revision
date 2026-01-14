//brute
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool duplicate(vector<int> v){
    int n=v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(v[i]==v[j]){
                return true;
            }
        }
        
    }
    return false;
    
}

//optimal
bool duplicates(vector<int>& v){
    unordered_set<int> s;
    for(int num:v){
        if(s.find(num)!=s.end()){
            return true;
        }
        s.insert(num);
    }
    return false;
}