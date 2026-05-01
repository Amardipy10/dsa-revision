#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<int>ans;
        bool flag=false;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[j]>arr[i]&&arr[j]>arr[k]){
                        flag =true;
                        ans.push_back(i+1);
                        ans.push_back(j+1);
                        ans.push_back(k+1);
                        break;
                    }
                }
            }
        }

        if(!flag){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            for(int i = 0; i < 3; i++){
                cout<<ans[i]<< " ";
            }
            cout<<endl;
        }
    }
}