//brute
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if(nums[i]==0 &&nums[j]!=0){
                    swap(nums[i],nums[j]);
                }
            }
        }
        
    }
};

//optimise

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0; // next position for non-zero

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[k], nums[i]);
                k++;
            }
        }
    }
};
