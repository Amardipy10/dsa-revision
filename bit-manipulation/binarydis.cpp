#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        if(__builtin_popcount(n)<2){
            return 0;
        }
        string s="";
        while(n>0){
            s=to_string(n%2)+s;
            n=n/2;
        }
        int maxDis=0;
        int dist=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==1){
                for(int j=i+1;j<s.size();j++){
                    if(s[j]==1){
                        dist=j-i;
                        maxDis=max(maxDis,dist);
                        break;
                    }
                }
            }
        }
        return maxDis;
    }
};

int main() {
    Solution obj;
    int n = 22;
    cout << "Binary Gap: " << obj.binaryGap(n);
    return 0;
}