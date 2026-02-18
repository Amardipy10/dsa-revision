class Solution {
public:
    bool hasAlternatingBits(int n) {
    string binary = "";
    while(n > 0){
        binary = to_string(n % 2) + binary;
        n = n / 2;
    }
    for(int i=0;i<binary.size();i++){
        if(binary[i]==binary[i+1]){
            return false;
        }
    }
    return true;
    }e
    };