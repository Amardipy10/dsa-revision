#include<iostream>
using namespace std;
class Solution {
public:
    bool isValid(int arr[], int n, int m, int maxAllowedPages) {
        int students = 1;
        int pages = 0;

        for (int i = 0; i < n; i++) {
            // single book > allowed pages → invalid
            if (arr[i] > maxAllowedPages) {
                return false;
            }

            if (pages + arr[i] <= maxAllowedPages) {
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];

                if (students > m) {
                    return false;
                }
            }
        }
        return true;
    }

    int findPages(int arr[], int n, int m) {
        if (m > n) return -1;

        int st = 0;
        int end = 0;

        for (int i = 0; i < n; i++) {
            end += arr[i];   // sum of array
        }

        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(arr, n, m, mid)) {
                ans = mid;        // valid → store answer
                end = mid - 1;    // move left
            } else {
                st = mid + 1;     // invalid → move right
            }
        }
        return ans;
    }
};