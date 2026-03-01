class Solution {
public:
    int findComplement(int num) {
        string s="";
        while(num>0){
            s=to_string(num%2)+s;
            num=num/2;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        return stoll(s,0,2);
    }
};