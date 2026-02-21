class Solution {
public:

    bool isPrime(int num){
        if(num==1||num==0){
            return false;
        }
        for(int i=2;i<num;i++){
            if(num%i==0){
                return false;
            }    
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int result=0;
        for(int i=left;i<=right;i++){
            string k="";
            int z=i;
            while(z>0){
                k=to_string(z%2)+k;
                z=z/2;
            }
            int count1=0;
            for(int i=0;i<k.size();i++){
                if(k[i]=='1'){
                    count1++;
                }
            }
            if(isPrime(count1)){
                result++;
            }
        }
        return result;
    }
};