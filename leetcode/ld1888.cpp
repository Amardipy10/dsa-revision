#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string target = s + s;
        string s1 = "", s2 = "";
        
        for (int i = 0; i < target.length(); i++) {
            s1 += (i % 2 == 0) ? '0' : '1';
            s2 += (i % 2 == 0) ? '1' : '0';
        }
        
        int res = n;
        int diff1 = 0, diff2 = 0;
        
        for (int i = 0; i < target.length(); i++) {
            if (target[i] != s1[i]) diff1++;
            if (target[i] != s2[i]) diff2++;
            
            if (i >= n) {
                if (target[i - n] != s1[i - n]) diff1--;
                if (target[i - n] != s2[i - n]) diff2--;
            }
            
            if (i >= n - 1) {
                res = min({res, diff1, diff2});
            }
        }
        
        return res;
    }
};