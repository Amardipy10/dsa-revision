#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) if (c == '0') initial_zeros++;

        if (initial_zeros == 0) return 0;
        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[initial_zeros] = 0;
        q.push(initial_zeros);
        vector<int> next_unvisited[2];
        for (int i = 0; i <= n; ++i) {
            if (i != initial_zeros) {
                next_unvisited[i % 2].push_back(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == 0) return dist[i];
            int min_j = max(0, k - (n - i));
            int max_j = min(i, k);
            int low = i + k - 2 * max_j;
            int high = i + k - 2 * min_j;
            int parity = low % 2;
            auto& unvisited = next_unvisited[parity];
            auto it_start = lower_bound(unvisited.begin(), unvisited.end(), low);
            auto it_end = upper_bound(unvisited.begin(), unvisited.end(), high);

            for (auto it = it_start; it != it_end; ++it) {
                if (dist[*it] == -1) {
                    dist[*it] = dist[i] + 1;
                    q.push(*it);
                }
            }
            unvisited.erase(it_start, it_end);
        }

        return -1;
    }
};