#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {nums[i], i};
        }
        sort(items.begin(), items.end());
        
        vector<int> minDists(n, -1);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && items[j].first == items[i].first) {
                j++;
            }
            
            int k = j - i;
            if (k > 1) {
                for (int p = 0; p < k; ++p) {
                    int cur = items[i + p].second;
                    int prev = items[i + (p - 1 + k) % k].second;
                    int next = items[i + (p + 1) % k].second;
                    
                    int d1 = (cur - prev + n) % n;
                    int d2 = (next - cur + n) % n;
                    
                    minDists[cur] = min(d1, d2);
                }
            }
            i = j;
        }
        
        int qSize = queries.size();
        vector<int> answer(qSize);
        for (int k = 0; k < qSize; ++k) {
            answer[k] = minDists[queries[k]];
        }
        
        return answer;
    }
};