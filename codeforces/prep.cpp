#include<bitset>/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        int low=0;
        int high=n-1;
        while(low<high){
            if(s[low]==0 && s[high]=1 || s[low]=1 && s[high]=0){
                low--;
                high++;
            }
            else if(low==high){
                cout<<1;
            }
            else{
                cout<<high-low+1;
            }
        }
    }
    return 0;
}