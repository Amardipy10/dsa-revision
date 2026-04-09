#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int p : piles) {
            if (p > right) right = p;
        }
        int result = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;            
            if (canFinish(piles, h, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
private:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (int p : piles) {
            // Ceiling division: (p + k - 1) / k
            totalHours += (p + k - 1LL) / k;
        }
        return totalHours <= h;
    }
};