class Solution {
public:
    int hammingDistance(int x, int y) {
        string a="";
        string b="";
        int p=x;
        int q=y;
        while(x>0){
            a=to_string(x%2)+a;
            x=x/2;
        }
        while(y>0){
            b=to_string(y%2)+b;
            y=y/2;
        }
        int count=0;
        int minm=min(a.size(),b.size());
        int maxm=max(a.size(),b.size());
        int ans=maxm-minm;
        if(p>q){
            b=string(ans,'0')+b;
        }
        else{
            a=string(ans,'0')+a;
        }
        for(int i=0;i<maxm;i++){
            if(a[i]!=b[i]){
                count++;
            }
        }
        
    return count;
}
};