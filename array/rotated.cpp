#include<iostream>
#include<vector>
#include<climits>

//brute
using namespace std;
int rotated(vector<int>& nums){
    int n=nums.size();
    int smallest=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        smallest=min(nums[i],smallest);
    }
    for (int i = 0; i < n; i++)
    {
        if(nums[i]==smallest){
            return i;
        }
    }
    return 0;
    
}

//optimal
#include <iostream>
#include <vector>
using namespace std;

int rotated(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;  // index of minimum element
}