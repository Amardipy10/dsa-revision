#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> A(n);
        
        // Step 1: Map each point to a 1D coordinate along the perimeter
        for(int i = 0; i < n; ++i) {
            long long x = points[i][0];
            long long y = points[i][1];
            
            if (y == 0) {
                A[i] = x;
            } else if (x == side) {
                A[i] = side + y;
            } else if (y == side) {
                A[i] = 2LL * side + (side - x);
            } else {
                A[i] = 3LL * side + (side - y);
            }
        }
        
        // Sort points sequentially around the boundary
        sort(A.begin(), A.end());
        
        // Step 2: Double the array to handle cyclic constraints seamlessly
        vector<long long> B(2 * n);
        for(int i = 0; i < n; ++i) {
            B[i] = A[i];
            B[i + n] = A[i] + 4LL * side;
        }
        
        // Step 3 & 4: Binary Search for the optimal distance
        long long low = 1;
        long long high = 4LL * side / k; // Max theoretical distance for k points
        long long ans = 1;
        
        auto check = [&](long long D) {
            int m = 2 * n;
            vector<int> nxt(m + 1, m);
            int j = 0;
            
            // Two-pointer logic to rapidly lookup the next valid point index
            for(int i = 0; i < m; ++i) {
                while(j < m && B[j] - B[i] < D) {
                    j++;
                }
                nxt[i] = j;
            }
            
            // Try wrapping a chain of k points starting from every possible valid origin point
            for(int i = 0; i < n; ++i) {
                int curr = i;
                int step = 0;
                
                for(; step < k; ++step) {
                    curr = nxt[curr];
                    if(curr >= m) break; // Out of bounds, stop early
                }
                
                // Valid subset found if k successful jumps complete within 1 full loop
                if(step == k && curr <= i + n) {
                    return true;
                }
            }
            return false;
        };
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(check(mid)) {
                ans = mid;
                low = mid + 1; // Feasible, so attempt to find a larger distance
            } else {
                high = mid - 1; // Infeasible, shrink the search bound
            }
        }
        
        return (int)ans;
    }
};