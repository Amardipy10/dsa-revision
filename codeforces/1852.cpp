#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        vector<long long> ans;

        for(long long i=1;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                if(i*i!=n){
                    ans.push_back(n/i);
                }
            }
        }

        sort(ans.begin(),ans.end());

        int max_int=1;
        int interval=1;

        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]+1==ans[i+1]){
                interval++;
            }
            else{
                max_int=max(max_int,interval);
                interval=1;
            }
        }

        max_int=max(max_int,interval);
        cout<<max_int<<endl;
    }
}