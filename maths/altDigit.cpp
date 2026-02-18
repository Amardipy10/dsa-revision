class Solution {
public:
    int alternateDigitSum(int n) {
        int sum=0;
        string s="";
        s=to_string(n);
        for(int i=0;i<s.size();i++){
            int num=s[i]-'0';
            if(i%2!=0){
                sum+=((-1)*num);
            }
            else{
                sum+=num;
            }

        }
        return sum;
    }
};