#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x1,x2,k;
        cin>>n>>x1>>x2>>k;
        int min_dis=min(abs(x1-x2),n-abs(x1-x2));
        if(n<=3){
            cout<<min_dis<<endl;
        } 
        else{
            cout<<min_dis+k<<endl;
        }
    }
    return 0;
}