class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int maxFreq=0;
        for(int i=0;i<nums.size();i++){
            int freq=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==nums[i]){
                    return(nums[i]);
                }
                
            }

        }
        return 0;
    }
};