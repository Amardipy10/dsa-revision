#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        // edge case
        if (n == 1) return arr[0];

        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // case 1: mid at start
            if (mid == 0 && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }

            // case 2: mid at end
            if (mid == n - 1 && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }

            // case 3: mid is the single element
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }

            // even index
            if (mid % 2 == 0) {
                if (arr[mid] == arr[mid + 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // odd index
            else {
                if (arr[mid] == arr[mid - 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};