// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const int MAXV = 1000005; 
// int f[MAXV];
// int t[500005], x[500005], y[500005];

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int q;
//     cin>>q;
//     for(int i=0;i<q;i++){
//         cin>>t[i];
//         if(t[i]==1) cin>>x[i];
//         else cin>>x[i]>>y[i];
//     }
//     for(int i=0;i<MAXV;i++) f[i]=i;
//     vector<int> out;
//     for(int i=q-1;i>=0;i--){
//         if(t[i]==1){
//             out.push_back(f[x[i]]);
//         }else{
//             int val=x[i];
//             int add=y[i];
//             if(val+add < MAXV && val+add >= 0){
//                 f[val]=f[val+add];
//             }
//         }
//     }
//     reverse(out.begin(),out.end());
//     for(int i=0;i<(int)out.size();i++){
//         cout<<out[i]<<(i==(int)out.size()-1?"":" ");
//     }
//     cout<<endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SZ = 1000007; 
int p[SZ];
int qt[500005], qx[500005], qy[500005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>qt[i];
        if(qt[i]==1) cin>>qx[i];
        else cin>>qx[i]>>qy[i];
    }
    for(int i=0;i<SZ;i++) p[i]=i;
    vector<int> ans;
    for(int i=q-1;i>=0;i--){
        if(qt[i]==1){
            ans.push_back(p[qx[i]]);
        }else{
            int u=qx[i], v=qy[i];
            if(u+v >= 0 && u+v < SZ){
                p[u]=p[u+v];
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i]<<(i==(int)ans.size()-1?"":" ");
    }
    cout<<"\n";
    return 0;
}