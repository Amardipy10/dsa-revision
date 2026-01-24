#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(nums[j]);
        j++;
    }

    // copy back to original array
    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
}

void mergesort(vector<int> &nums, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergesort(nums, left, mid);
    mergesort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}