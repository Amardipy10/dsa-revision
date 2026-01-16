 #include<iostream>
 #include<string>
 using namespace std;
 bool isAnagram(string s, string t) {
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

        
}