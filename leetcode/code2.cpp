// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <bitset>

// using namespace std;

// struct Query {
//     int idx;
//     long long x, y;
// };
// long long a[200005];
// bitset<500> tree[800005];
// long long ux[505];
// int M;
// void build(int node, int L, int R, const vector<bitset<500>>& init) {
//     if (L == R) {
//         tree[node] = init[L];
//         return;
//     }
//     int mid = (L + R) / 2;
//     build(2 * node, L, mid, init);
//     build(2 * node + 1, mid + 1, R, init);
//     tree[node] = tree[2 * node] | tree[2 * node + 1];
// }
// void apply(int node, int L, int R, int qL, int qR, int x_id, long long y) {
//     if (qL > R || qR < L || !tree[node].test(x_id)) return;
//     if (L == R) {
//         a[L] *= y;
//         for (int j = 0; j < M; ++j) {
//             if (tree[node].test(j)) {
//                 if (ux[j] % a[L] != 0) tree[node].reset(j);
//             }
//         }
//         return;
//     }
//     int mid = (L + R) / 2;
//     apply(2 * node, L, mid, qL, qR, x_id, y);
//     apply(2 * node + 1, mid + 1, R, qL, qR, x_id, y);
//     tree[node] = tree[2 * node] | tree[2 * node + 1];
// }
// void solve() {
//     int n, q;
//     if (!(cin >> n >> q)) return;
//     long long mx_x = 0;
//     for (int i = 0; i < n; i++) cin >> a[i];
//     vector<Query> qs(q);
//     vector<long long> all_x;
//     for (int i = 0; i < q; i++) {
//         cin >> qs[i].idx >> qs[i].x >> qs[i].y;
//         all_x.push_back(qs[i].x);
//         mx_x = max(mx_x, qs[i].x);
//     }
//     sort(all_x.begin(), all_x.end());
//     all_x.erase(unique(all_x.begin(), all_x.end()), all_x.end());
//     M = all_x.size();
//     for (int i = 0; i < M; i++) ux[i] = all_x[i];

//     vector<bitset<500>> init(n);
//     for (int i = 0; i < n; i++) {
//         if (a[i] > mx_x) continue;
//         for (int j = 0; j < M; j++) {
//             if (ux[j] % a[i] == 0) init[i].set(j);
//         }
//     }

//     build(1, 0, n - 1, init);

//     for (int i = 0; i < q; i++) {
//         if (qs[i].y == 1) continue;
//         int x_id = lower_bound(all_x.begin(), all_x.end(), qs[i].x) - all_x.begin();
//         apply(1, 0, n - 1, qs[i].idx - 1, n - 1, x_id, qs[i].y);
//     }

//     for (int i = 0; i < n; i++) {
//         cout << a[i] << (i == n - 1 ? "" : " ");
//     }
//     cout << "\n";
// }
// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) solve();
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <bitset>
// using namespace std;

// typedef long long ll;
// const int MAXN = 200005;

// struct Node {
//     int id;
//     ll x, y;
// };

// ll arr[MAXN];
// bitset<505> st[4 * MAXN];
// ll vals[505];
// int m_size;

// void build(int node, int L, int R, const vector<bitset<505>>& v) {
//     if (L == R) {
//         st[node] = v[L];
//         return;
//     }
//     int mid = (L + R) / 2;
//     build(2 * node, L, mid, v);
//     build(2 * node + 1, mid + 1, R, v);
//     st[node] = st[2 * node] | st[2 * node + 1];
// }

// void update(int node, int L, int R, int qL, int qR, int x_id, ll mult) {
//     if (qL > R || qR < L || !st[node].test(x_id)) return;
//     if (L == R) {
//         arr[L] *= mult;
//         for (int j = 0; j < m_size; j++) {
//             if (st[node].test(j) && (vals[j] % arr[L] != 0)) {
//                 st[node].reset(j);
//             }
//         }
//         return;
//     }
//     int mid = (L + R) / 2;
//     update(2 * node, L, mid, qL, qR, x_id, mult);
//     update(2 * node + 1, mid + 1, R, qL, qR, x_id, mult);
//     st[node] = st[2 * node] | st[2 * node + 1];
// }

// void solve() {
//     int n, q;
//     if (!(cin >> n >> q)) return;
//     ll limit = 0;
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     vector<Node> queries(q);
//     vector<ll> temp_x;
//     for (int i = 0; i < q; i++) {
//         cin >> queries[i].id >> queries[i].x >> queries[i].y;
//         temp_x.push_back(queries[i].x);
//         if(queries[i].x > limit) limit = queries[i].x;
//     }
//     sort(temp_x.begin(), temp_x.end());
//     temp_x.erase(unique(temp_x.begin(), temp_x.end()), temp_x.end());
//     m_size = temp_x.size();
//     for (int i = 0; i < m_size; i++) vals[i] = temp_x[i];

//     vector<bitset<505>> init_bits(n);
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > 2000000000LL) continue; // Optimization
//         for (int j = 0; j < m_size; j++) {
//             if (vals[j] % arr[i] == 0) init_bits[i].set(j);
//         }
//     }

//     build(1, 0, n - 1, init_bits);

//     for (int i = 0; i < q; i++) {
//         if (queries[i].y == 1) continue;
//         int x_idx = lower_bound(temp_x.begin(), temp_x.end(), queries[i].x) - temp_x.begin();
//         update(1, 0, n - 1, queries[i].id - 1, n - 1, x_idx, queries[i].y);
//     }

//     for (int i = 0; i < n; i++) cout << arr[i] << (i == n - 1 ? "" : " ");
//     cout << "\n";
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) solve();
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

const int MAXN = 200005;
ll a[MAXN];
set<int> has_div[505];
vector<int> belongs[MAXN];
ll ux[505];

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        belongs[i].clear();
    }
    for (int i = 0; i < 505; i++) has_div[i].clear();

    struct Query { int id; ll x, y; };
    vector<Query> qs(q);
    vector<ll> vx;
    for (int i = 0; i < q; i++) {
        cin >> qs[i].id >> qs[i].x >> qs[i].y;
        vx.push_back(qs[i].x);
    }

    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    int m = vx.size();
    for (int i = 0; i < m; i++) ux[i] = vx[i];

    for (int i = 1; i <= n; i++) {
        if (a[i] > 2000000000LL) continue;
        for (int j = 0; j < m; j++) {
            if (ux[j] % a[i] == 0) {
                has_div[j].insert(i);
                belongs[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (qs[i].y == 1) continue;
        int x_id = lower_bound(vx.begin(), vx.end(), qs[i].x) - vx.begin();
        
        auto it = has_div[x_id].lower_bound(qs[i].id);
        vector<int> targets;
        while (it != has_div[x_id].end()) {
            targets.push_back(*it);
            it++;
        }

        for (int idx : targets) {
            a[idx] *= qs[i].y;
            vector<int> next_b;
            for (int id : belongs[idx]) {
                if (ux[id] % a[idx] == 0) {
                    next_b.push_back(id);
                } else {
                    has_div[id].erase(idx);
                }
            }
            belongs[idx] = next_b;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? "" : " ");
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}