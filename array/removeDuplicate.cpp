#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0; // index of last unique element

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;             // move to next unique slot
                nums[i] = nums[j]; // copy unique element
            }
        }

        return i + 1; // total unique elements
    }
};