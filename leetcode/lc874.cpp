#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs_set;
        for (const auto& obs : obstacles) {
            obs_set.insert({obs[0], obs[1]});
        }

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, dir = 0;
        int max_dist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;
                    if (obs_set.count({nx, ny})) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    max_dist = max(max_dist, x * x + y * y);
                }
            }
        }

        return max_dist;
    }
};