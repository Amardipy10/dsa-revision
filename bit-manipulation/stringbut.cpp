#include<iostream>
#include<string>
using namespace std;
#include<unordered_set>

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>s1;
        for(int i=0;i<s.size();i++){
            string subs="";
            for(int j=i;j<k;j++){
                subs=subs+s[j];
            }
            s1.insert(subs);
        }
        if(s1.size()==pow(2,k)){
            return true;
        }
        return false;
        for (auto x : s1) {
        cout << x << " ";
        }
    }
};

int main(){
    Solution obj;
    obj.hasAllCodes("00110110",2);

}