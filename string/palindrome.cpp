#include<iostream>
#include<string>
using namespace std;

// bool isPalindrome(int x) {
//     string s=to_string(x);
//     string p;
// for (int i = s.size()-1; i >0; i--)
// {
//     p.push_back(s[i]);
// }

    
//     if(s==p){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

class Solution {
public:
    bool isPalindrome(long x) {
    long r=0;
    long c=x;
    if(x<0){
        return false;
    }
    while(x>0){
        r=(r*10)+(x%10);
        x=x/10;
    
    }
    if(c==r){
        return true;
    }
    else{
        return false;
    }
    }
};