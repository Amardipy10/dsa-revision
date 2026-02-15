class Solution {
public:
    bool isPowerOfFour(double n) {
        
        while(n>1){
            n=n/4;
        }
        if(n==1){
            return true;
        }
        return false;
        
    }
};
