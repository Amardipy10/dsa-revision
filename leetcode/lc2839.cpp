class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int i=0;
        int j=2;
        swap(s1[i],s1[j]);
        if(s1==s2){
            return true;
        }
        swap(s1[i],s1[j]);
        i++;
        j++;
        swap(s1[i],s1[j]);
        if(s1==s2){
            return true;
        }
        int l=0;
        int m=2;
        swap(s1[l],s1[m]);
        if(s1==s2){
            return true;
        }
        return false;
    }
};