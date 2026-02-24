class Solution {
public:
    int arrangeCoins(int n) {
        int count=0;
        int i=1;
        while(n>0 && n>=i){
            n=n-i;
            i=i+1;
            count++;
        }
        return count;
    }
};