class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        vector<vector<pair<int,int>>> dirs = {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };

        auto ok = [&](int type, int dx, int dy) {
            if (type == 1) return dy != 0;
            if (type == 2) return dx != 0;
            if (type == 3) return (dx == 0 && dy == -1) || (dx == 1 && dy == 0);
            if (type == 4) return (dx == 0 && dy == 1) || (dx == 1 && dy == 0);
            if (type == 5) return (dx == 0 && dy == -1) || (dx == -1 && dy == 0);
            return (dx == 0 && dy == 1) || (dx == -1 && dy == 0);
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == m - 1 && y == n - 1) return true;

            int type = grid[x][y];
            for (auto [dx, dy] : dirs[type]) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
                if (ok(grid[nx][ny], -dx, -dy)) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
};