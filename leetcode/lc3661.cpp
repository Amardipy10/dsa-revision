#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> robs(n);
        for (int i = 0; i < n; ++i) {
            robs[i] = {robots[i], distance[i]};
        }
        sort(robs.begin(), robs.end());
        sort(walls.begin(), walls.end());

        int base_walls = 0;
        vector<int> clean_walls;
        clean_walls.reserve(walls.size());
        
        int r_idx = 0;
        for (int w : walls) {
            while (r_idx < n && robs[r_idx].first < w) {
                r_idx++;
            }
            if (r_idx < n && robs[r_idx].first == w) {
                base_walls++;
            } else {
                clean_walls.push_back(w);
            }
        }

        auto count_w = [&](int L, int R) {
            if (L > R) return 0;
            auto it1 = lower_bound(clean_walls.begin(), clean_walls.end(), L);
            auto it2 = upper_bound(clean_walls.begin(), clean_walls.end(), R);
            return (int)(it2 - it1);
        };

        int dp0 = count_w(robs[0].first - robs[0].second, robs[0].first - 1);
        int dp1 = 0;

        for (int i = 1; i < n; ++i) {
            int L_bound = robs[i-1].first + 1;
            int R_bound = robs[i].first - 1;
            
            int W10 = 0, W01 = 0, W11 = 0;
            if (L_bound <= R_bound) {
                int R_reach = min(R_bound, robs[i-1].first + robs[i-1].second);
                int L_reach = max(L_bound, robs[i].first - robs[i].second);
                
                W10 = count_w(L_bound, R_reach);
                W01 = count_w(L_reach, R_bound);
                
                int overlap_L = max(L_bound, L_reach);
                int overlap_R = min(R_bound, R_reach);
                int overlap = count_w(overlap_L, overlap_R);
                
                W11 = W10 + W01 - overlap;
            }
            
            int new_dp0 = max(dp0 + W01, dp1 + W11);
            int new_dp1 = max(dp0 + 0, dp1 + W10);
            
            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        int final_reach = count_w(robs[n-1].first + 1, robs[n-1].first + robs[n-1].second);
        return base_walls + max(dp0, dp1 + final_reach);
    }
};