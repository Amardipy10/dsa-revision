class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int students = 1;
        int pages = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (pages + arr[i] <= mid) {
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];
            }
        }

        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }

        return ans;
    }
};