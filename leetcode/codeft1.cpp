// #include <iostream>
// #include <vector>
// using namespace std;
// void solve(){
//     int n;
//     cin>>n;
//     vector<long long>a(n);
//     long long totalXOR=0;
//     for (int i=0;i<n;i++) {
//         cin>>a[i];
//         totalXOR^=a[i];
//     }
//     if(totalXOR==0){
//         cout<<"YES"<<endl;
//         return;
//     }
//     bool possible=false;
//     for(int i=0;i<n;i++) {
//         if ((totalXOR^a[i])==0) {
//             possible=true;
//             break;
//         }
//     }
//     if(possible){
//         cout<<"YES"<< endl;
//     } else{
//         cout<<"NO"<<endl;
//     }
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long> v(n);
    long long x=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        x^=v[i];
    }
    if(x==0){
        cout<<"YES"<<endl;
        return;
    }
    bool ok=false;
    for(int i=0;i<n;i++){
        if(v[i]==x){
            ok=true;
            break;
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}