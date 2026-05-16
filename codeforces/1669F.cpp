#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>can(n);
        for(int i=0;i<n;i++){
            cin>>can[i];
        }
        int left=0;
        int right=n-1;
        int leftcount=can[left];
        int rightcount=can[right];
        int maxcandy=0;
        int candy=2;
        while(left<right){
            if(leftcount==rightcount){
                maxcandy=max(maxcandy,candy);
                left++;
                leftcount+=can[left];
                right--;
                rightcount+=can[right];
                candy+=2;
            }
            else if(leftcount<rightcount){
                left++;
                leftcount+=can[left];
                candy++;
            }
            else{
                right--;
                rightcount+=can[right];
                candy++;
            }

            
        }
        cout<<maxcandy<<endl;
    }
}