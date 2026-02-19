class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int result=0;
        result=accumulate(reward2.begin(),reward2.end(),0);
        int n=reward1.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=reward1[i]-reward2[i];
        }
        sort(ans.begin(),ans.end());
        for(int i=n-1;i>(n-k-1);i--){
            result+=ans[i];
        }
        return result;
    }
};