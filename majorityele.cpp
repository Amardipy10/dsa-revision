#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             int count = 1;  // count nums[i] itself

//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] == nums[j]) {
//                     count++;
//                 }
//             }

//             if (count > n / 2) {
//                 return nums[i];
//             }
//         }
//         return -1; // just for safety
//     }
// };

//optimal //hashing

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> freq;
//         for(int num:nums){
//             freq[num]++;
//         }
//         int n=nums.size();
//         for(int num:nums){
//             if(freq[num]>n/2){
//                 return num;
//             }
//         }
//         return -1;
        
//     }
// };

//moore voting algo space(1)

class Solution{
    public:
    int majorityElement(vector<int>& nums){
        int candidate=0;
        int count=0;
        int n=nums.size();
        for (int i = 0; i < n; i++)
        {
            if(count==0){
                candidate=nums[i];
                count++;
            }
            else if(count>=1 && candidate==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
        
    }
};