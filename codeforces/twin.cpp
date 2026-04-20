#include<bits/stdc++.h>

using namespace std;
void tc(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cout<<n+1-x<<' ';
    }
    cout<<'\n';
}
int main()
{
    int t; cin>>t; while(t--)
        tc();
    return 0;
}