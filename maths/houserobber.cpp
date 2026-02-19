class Solution {
public:
    int rob(vector<int>& nums) {
        int total=0;
        int total2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                total+=nums[i];
            }
            else{
                total2+=nums[i];
            }
        }
        return max(total,total2);
    }
};