#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int runnerUp(vector<int>& nums) {
        int maxVal = INT_MIN;
        int secMax = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxVal) {
                secMax = maxVal;
                maxVal = nums[i];
            }
            else if(nums[i] < maxVal && nums[i] > secMax) {
                secMax = nums[i];
            }
        }
        return secMax;
    }
};
