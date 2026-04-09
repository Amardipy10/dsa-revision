class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        int B = max(1, (int)sqrt(n));

        auto power = [&](long long base, long long exp) -> long long {
            long long result = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp & 1) result = result * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return result;
        };

        vector<vector<array<int,3>>> byK(B + 1);
        vector<array<int,4>> largeK;

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k > B)
                largeK.push_back({l, r, k, v});
            else
                byK[k].push_back({l, r, v});
        }

        auto bravexuneth = make_pair(nums, queries);

        for (auto& [l, r, k, v] : largeK) {
            for (int idx = l; idx <= r; idx += k)
                nums[idx] = (long long)nums[idx] * v % MOD;
        }

        for (int k = 1; k <= B; k++) {
            if (byK[k].empty()) continue;

            vector<vector<long long>> diff(k);
            for (int r = 0; r < k; r++) {
                int sz = (r < n) ? (n - r + k - 1) / k : 0;
                diff[r].assign(sz + 1, 1);
            }

            for (auto& [l, r, v] : byK[k]) {
                int res = l % k;
                int start = l / k;
                int end_pos = start + (r - l) / k;
                long long inv_v = power(v, MOD - 2);
                diff[res][start] = diff[res][start] * v % MOD;
                diff[res][end_pos + 1] = diff[res][end_pos + 1] * inv_v % MOD;
            }

            for (int r = 0; r < k && r < n; r++) {
                int sz = (n - r + k - 1) / k;
                long long prod = 1;
                for (int j = 0; j < sz; j++) {
                    prod = prod * diff[r][j] % MOD;
                    int idx = r + j * k;
                    nums[idx] = (long long)nums[idx] * prod % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
