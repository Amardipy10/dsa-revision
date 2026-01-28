#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

    bool isAlpha(char ch){
            if(ch>='0'&&ch<='9'||tolower(ch)>='a'&&tolower(ch)<='z'){
                return true;
            }
            return false;
        }
    bool  isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<end){
            if(!isAlpha(s[start])){
                start++;
            }
            else if(!isAlpha(s[end])){
                end--;
            }
            else if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
        }
        
        
    };
