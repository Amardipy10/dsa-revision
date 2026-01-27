#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] < 9) {
                arr[i] += 1;
                return arr;
            }
            arr[i] = 0;
        }
        
        arr.insert(arr.begin(), 1);
        return arr;
    }
};