#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto canReduce = [&](long long timeLimit) {
            long long totalHeight = 0;
            for (int w : workerTimes) {
                long long x = (-1 + sqrt(1 + 8.0 * timeLimit / w)) / 2;
                totalHeight += x;
                if (totalHeight >= mountainHeight) return true;
            }
            return totalHeight >= mountainHeight;
        };

        long long low = 0;
        long long maxW = *max_element(workerTimes.begin(), workerTimes.end());
        long long high = maxW * (long long)mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canReduce(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};