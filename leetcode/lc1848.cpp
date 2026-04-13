class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int minm=INT_MAX;
        for (int i=0;i<n;i++){
                int index=abs(i-start);
                if(nums[i]==target && index<minm){
                    minm=index;
                }
        }
        return minm;
    }
};