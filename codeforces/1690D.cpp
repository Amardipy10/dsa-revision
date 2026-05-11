#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;
        cin>>s;
        int count=0;
        int consec=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                count++;
            }
            else{
                consec=max(consec,count);
                count=0;
            }
        }
        consec=max(consec,count);
        if(consec>=k){
            cout<<0<<endl;
        }
        else{
            int window=k;
            
            int minB=INT_MAX;
            for(int i=0;i<n;i++){
                int cnt=0;
                for(int j=i;j<window+i;j++){
                    if(s[j]=='B'){
                        cnt++;
                    }
                }
                minB=min(minB,k-cnt);
            }
            cout<<minB<<endl;
        }
    }
}