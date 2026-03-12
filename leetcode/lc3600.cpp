#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    struct Edge {
        int u, v, s, must;
    };

    struct DSU {
        vector<int> parent;
        int components;
        DSU(int n) : parent(n), components(n) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                components--;
                return true;
            }
            return false;
        }
    };

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int m = edges.size();
        vector<Edge> edgeList(m);
        DSU check_must(n);

        for (int i = 0; i < m; ++i) {
            edgeList[i] = {edges[i][0], edges[i][1], edges[i][2], edges[i][3]};
            if (edgeList[i].must == 1) {
                if (!check_must.unite(edgeList[i].u, edgeList[i].v)) return -1;
            }
        }

        auto check = [&](int threshold) {
            DSU dsu(n);
            int upgrades_used = 0;
            int edges_in_mst = 0;

            for (const auto& e : edgeList) {
                if (e.must == 1) {
                    if (e.s < threshold) return false;
                    if (dsu.unite(e.u, e.v)) edges_in_mst++;
                }
            }

            for (const auto& e : edgeList) {
                if (e.must == 0 && e.s >= threshold) {
                    if (dsu.unite(e.u, e.v)) edges_in_mst++;
                }
            }

            for (const auto& e : edgeList) {
                if (e.must == 0 && e.s < threshold && (2 * e.s) >= threshold) {
                    if (upgrades_used < k) {
                        if (dsu.unite(e.u, e.v)) {
                            upgrades_used++;
                            edges_in_mst++;
                        }
                    }
                }
            }
            return dsu.components == 1 && edges_in_mst == n - 1;
        };

        int low = 1, high = 200000, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};