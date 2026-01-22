#include<iostream>
#include<vector>

using namespace std;
void insertion(vector<int> &v){
    int n=v.size();
    for (int i = 1; i < n; i++)
    {
        int prev=i-1;
        int curr=v[i];
        while(prev>=0 && curr<v[prev]){
            v[prev+1]=v[prev];
            prev--;
        }
        v[prev+1]=curr;
    }
    
}

int main(){
    vector<int> v={34,32,3,21,321};
    insertion(v);
    for(int i: v){
        cout<<i<<" ";;
    }
    return 0;

}