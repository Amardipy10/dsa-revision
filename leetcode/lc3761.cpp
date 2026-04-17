class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = -1;
        unordered_map<int, int> last_seen_rev;

        for (int j = 0; j < n; ++j) {
            if (last_seen_rev.find(nums[j]) != last_seen_rev.end()) {
                int dist = j - last_seen_rev[nums[j]];
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                }
            }

            long long rev = 0;
            int temp = nums[j];
            while (temp > 0) {
                rev = rev * 10 + (temp % 10);
                temp /= 10;
            }

            if (rev <= 1000000000) {
                last_seen_rev[(int)rev] = j;
            }
        }

        return min_dist;
    }
};