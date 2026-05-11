#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string p;
        cin>>p;
        string s;
        s=p+p;
        int count=0;
        int max_count=0;
        if(c=='r'){
            for(int i=0;i<n+n;i++){
                if(s[i]=='r'){
                    count++;
                }
                else if(s[i]=='y'&&count>0){
                    count++;
                }
                else{
                    max_count=max(max_count,count);
                    count=0;
                }
                max_count=max(max_count,count);
            }
        }
        if(c=='y'){
            for(int i=0;i<n+n;i++){
                if(s[i]=='y'){
                    count++;
                }
                else if(s[i]=='r'&&count>0){
                    count++;
                }
                else{
                    max_count=max(max_count,count);
                    count=0;
                }
                max_count=max(max_count,count);
            }
        }
        cout<<max_count<<endl;
    }
} 